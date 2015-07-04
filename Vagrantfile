# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  # Start from closest model to Travis CI
  # http://about.travis-ci.org/docs/user/ci-environment/#CI-environment-OS
  config.vm.box = "precise64"
  config.vm.box_url = "http://files.vagrantup.com/precise64.box"
  config.ssh.shell = "bash -c 'BASH_ENV=/etc/profile exec bash'"

  # Verify environment is properly configured
  $configure_env = <<SCRIPT
  if test "$VAGRANT" != "true"; then
    echo "VAGRANT=true" >> /etc/environment
  fi
SCRIPT
  config.vm.provision "shell", inline: $configure_env

  config.vm.provision "shell", path: "env/provision.sh"
end
