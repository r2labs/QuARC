#!/usr/bin/env bash
# Output commands and exit on first failure
set -e
set -x

sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test && \
    sudo apt-get update -qq
sudo apt-get install -qq -y g{cc,++}-4.8 valgrind libboost1.48-all-dev
sudo pip install --upgrade pip cpp-coveralls
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 90
sudo update-alternatives --install /usr/bin/gcov gcov /usr/bin/gcov-4.8 90

cat <<EOF >> /home/vagrant/.bashrc
export CMAKE_ARGS="-DPROFILE=1"
source /vagrant/configure
build() {
    reconfigure ${CMAKE_ARGS} && make
}
test() {
    reconfigure ${CMAKE_ARGS} && make && make test
}
EOF
