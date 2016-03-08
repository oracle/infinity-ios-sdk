#!/bin/bash

# publishTestPod.sh
# Publishes the contents of the ios-lib to a test repo for pod testing
# This script should be run after Jenkins builds the pod.
# Download the package from Artifactory, extract it into a test pod repo
# and run this script.

# Set the script to abort if any commands fail
set -e

# Set up some variables
PODSPEC=Webtrends-SDK.podspec

# Check if Cocoapods is installed
type pod >/dev/null 2>&1 || { echo >&2 "ERROR: I require Cocoapods but it's not installed.  Aborting."; exit 1; }
echo "Cocoapods is installed."

# Check if Git is installed
type git >/dev/null 2>&1 || { echo >&2 "ERROR: I require git but it's not installed.  Aborting."; exit 1; }
echo "Git is installed."

# Check if the $TEST_POD_REPO_DIR environment variable is set. If not, set it to ~/Dev/ios-test-pod
REPODIR=${TEST_POD_REPO_DIR:-~/Dev/ios-test-pod}
echo "Local git repo is $REPODIR"


# Check to see if we are in the right directory
DIRECTORIES=( 'Documentation' 'Headers' 'SharedAssets' 'WatchHeaders' )
for d in "${DIRECTORIES[@]}"
do
	if [ ! -d "${d}" ]; then
		echo "ERROR: Cannot find the ${d} directory. This script is not running in the correct directory. Please run it from the Webtrends-SDK extracted tarball.";
		exit 1;
	fi
done
echo "Running in the correct directory"


# Copy the files into the test pod repo directory (only if we're not already there).
if [ ! "$PWD" = "$REPODIR" ]; then
	echo "Copying files...";
	cp -R ./. $REPODIR;
else
	echo "No need to copy anything. We're already in the repo directory.";
fi

cd $REPODIR
if [ -d .git ]; then
  echo "Found your git repo.";
else
  echo >&2 "ERROR: $REPODIR is not a valid git repo. Set REPODIR to your ios-test-pod directory"
fi;

# Check the podspec file
if [ -e $PODSPEC ]; then
  echo "Found the podspec file.";
else
  echo >&2 "ERROR: Podspec file $PODSPEC does not exist. Aborting."
  exit 1;
fi;


# Get the tag of the last pod version
PREV_VERSION="$(git ls-remote --tags | grep -o '[0-9]*\.[0-9]*\.[0-9]*' | sort -r | head -n 1 | grep -o '[^\/]*$')"
echo "The last commited version was $PREV_VERSION"

# Increment the version
NEXT_VERSION=${PREV_VERSION%.*}.$((${PREV_VERSION##*.}+1))
echo "Next version will be: $NEXT_VERSION"

# Make some changes to the podspec file
# 1. Point the source to the test repo
# 2. Change the pod version
echo "Editing the podspec file"
cat Webtrends-SDK.podspec | \
	sed "s/https:\/\/github.com\/webtrends\/ios-sdk.git/https:\/\/gh.webtrends.corp\/cloughb\/ios-pod.git/g" | \
	sed "s/3.0.0/$NEXT_VERSION/g" > Webtrends-SDK.podspec.tmp
echo "Overwriting the podspec file with the edited one"
mv Webtrends-SDK.podspec.tmp Webtrends-SDK.podspec

# pull the repo
git pull origin master
# commit the changes
git add .
git commit -m "$NEXT_VERSION"
git tag $NEXT_VERSION
git push origin master
git push --tags

# Check the podspec file for accuracy (lint)
echo "Linting the podspec file $PODSPEC"
pod spec lint 2>&1 || { echo >&2 "ERROR: Podspec file does not lint. Aborting."; exit 1; }


# Push the pod
pod repo push Webtrends-SDK $PODSPEC
