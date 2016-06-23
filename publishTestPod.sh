#!/bin/bash

# publishTestPod.sh
# Publishes the contents of the ios-lib to a test repo for pod testing
# This script should be run after Jenkins builds the pod.
# Download the package from Artifactory, extract it into a test pod repo
# and run this script.

# Set the script to abort if any commands fail
set -e

# Set up some variables
PODSPEC=Webtrends-SDK
PODURL=https://gh.webtrends.corp/qa/ios-staging-pod

# Check if Cocoapods is installed
type pod >/dev/null 2>&1 || { echo >&2 "ERROR: I require Cocoapods but it's not installed.  Aborting."; exit 1; }
echo "Cocoapods is installed."

# Check if Git is installed
type git >/dev/null 2>&1 || { echo >&2 "ERROR: I require git but it's not installed.  Aborting."; exit 1; }
echo "Git is installed."

# Check if the $TEST_POD_REPO_DIR environment variable is set. If not, set it to ~/Dev/ios-test-pod
REPODIR=${TEST_POD_REPO_DIR:-~/Dev/ios-staging-pod}
echo "Local git repo is $REPODIR"

# Check if pod repo exists and remove it to ensure that it will be correct.
if [ ! -e ~/.cocoapods/$PODSPEC ]; then
	pod repo remove "$PODSPEC"
fi
# Now add the correct repo in
pod repo add "$PODSPEC" "$PODURL"


# Check to see if we are in the right directory
DIRECTORIES=( 'Headers' 'SharedAssets' 'WatchHeaders' )
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
	cp -R ./. "$REPODIR";
else
	echo "No need to copy anything. We're already in the repo directory.";
fi

cd "$REPODIR"
if [ -d .git ]; then
  echo "Found your git repo.";
else
  echo >&2 "ERROR: $REPODIR is not a valid git repo. Set REPODIR to your ios-test-pod directory"
fi;

# Check the podspec file
if [ -e $PODSPEC.podspec ]; then
  echo "Found the podspec file.";
else
  echo >&2 "ERROR: Podspec file $PODSPEC.podspec does not exist. Aborting."
  exit 1;
fi;


# Get the tag of the last pod version
# Get a list of remote tags
# Extract out just the version numbers
# Turn all numbers into double digits
# Sort the results
# Turn them back into single digits
# Report the last one
PREV_VERSION="$(git ls-remote --tags | grep -o '[0-9]*\.[0-9]*\.[0-9]*' | sed 's/^[0-9]\./0&/; s/\.\([0-9]\)$/.0\1/; s/\.\([0-9]\)\./.0\1./g; s/\.\([0-9]\)\./.0\1./g' | sort | sed 's/^0// ; s/\.0/./g' | tail -1)" 

echo "The last commited version was $PREV_VERSION"

# Increment the version
NEXT_VERSION=${PREV_VERSION%.*}.$((${PREV_VERSION##*.}+1))
echo "Next version will be: $NEXT_VERSION"

# Make some changes to the podspec file
# 1. Point the source to the test repo
# 2. Change the pod version
echo "Editing the podspec file"
sed "s/https:\/\/github.com\/webtrends\/ios-sdk.git/https:\/\/gh.webtrends.corp\/qa\/ios-staging-pod.git/g" < "$PODSPEC".podspec | \
	sed "s/3.0.0/$NEXT_VERSION/g" > "$PODSPEC".tmp
echo "Overwriting the podspec file with the edited one"
mv "$PODSPEC".tmp "$PODSPEC".podspec

# pull the repo
git pull origin master
# commit the changes
git add .
git commit -m "$NEXT_VERSION"
git tag "$NEXT_VERSION"
git push origin master
git push --tags

# Check the podspec file for accuracy (lint)
echo "Linting the podspec file $PODSPEC.podspec"
pod spec lint Webtrends-SDK 2>&1 || { echo >&2 "ERROR: Podspec file does not lint. Aborting."; exit 1; }


# Push the pod
pod repo push Webtrends-SDK $PODSPEC.podspec
