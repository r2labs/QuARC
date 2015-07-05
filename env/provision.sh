#!/usr/bin/env bash
set -e    # exit on first failure
set -x    # output each executed command

apt='sudo apt-get -qq -y'
updated_flag=.updated_apt_get
installed_flag=.installed_dependencies

if ! test -f ${updated_flag}; then
    touch ${updated_flag}
    ${apt} update
fi

if ! test -f ${installed_flag}; then
    touch ${installed_flag}
    ${apt} install curl git python-software-properties
    ${apt} install {c,}make build-essential python-{pip,dev}
    sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test && \
        ${apt} update
    ${apt} install  g{cc,++}-4.8 valgrind libboost1.48-all-dev
    sudo pip install --upgrade pip cpp-coveralls
    sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 90
    sudo update-alternatives --install /usr/bin/gcov gcov /usr/bin/gcov-4.8 90
    cat <<EOF >> /home/vagrant/.bashrc
export CMAKE_ARGS="-DPROFILE=1"
source /vagrant/configure
EOF
fi
