#!/bin/bash

BRANCH=$1
VERSION=$2
CONTAINER=$3

if [ -z "$BRANCH" ]
then
      echo "A branch is not set."
      exit 1
fi

if [ -z "$VERSION" ]
then
      echo "The base version is not set."
      exit 1
fi

if [ -z "$CONTAINER" ]
then
      echo "The base container is not set."
      exit 1
fi

git fetch --tags

if [ "$BRANCH" = "master" ]
then
    echo "$VERSION"
    exit 0
fi

LABEL="develop"
if [ "$BRANCH" = "stable" ]
then
    LABEL="stable"
elif [ "$BRANCH" = "beta" ]
then
    LABEL="beta"
fi

for (( VERSION_NUMBER=0; ; VERSION_NUMBER++ ))
do
    if [ "$VERSION" = "1.49" ] && [ "$VERSION_NUMBER" -le 4 ]
    then
        VERSION_NUMBER=4
    fi
    RESULT_VERSION="$CONTAINER.$VERSION-$LABEL.$VERSION_NUMBER"
    if ! [ $(git tag -l ?$RESULT_VERSION) ]
    then
        echo "$RESULT_VERSION"
        break
    fi
done
