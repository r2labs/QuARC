#!/usr/bin/env bash
# Output commands and exit on first failure
set -e
set -x

# Update apt-get once
if ! test -f .updated_apt_get; then
    sudo apt-get update
    touch .updated_apt_get
fi

# Install `node` for testing
if ! which node > /dev/null; then
    sudo apt-get install -qq -y python-software-properties
    sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
    sudo apt-get update -qq
    sudo apt-get install -qq -y g{cc,++}-4.8 valgrind libboost1.48-all-dev make python-{pip,dev} build-essential cmake
    sudo pip install --upgrade pip virtualenv{,wrapper} cpp-coveralls
    sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 90
    sudo update-alternatives --install /usr/bin/gcov gcov /usr/bin/gcov-4.8 90
fi
