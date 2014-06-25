# -*- mode: ruby -*-
# vi: set ft=ruby :
ROOT = File.dirname(File.absolute_path(__FILE__))

# Vagrantfile API/syntax version. Don't touch unless you know what you're doing!
VAGRANTFILE_API_VERSION = "2"
Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
    
    config.vm.synced_folder ".", "/vagrant", disabled: true
    
    config.vm.define "hhvm" do |v|
    
        v.vm.synced_folder File.absolute_path("./hhvm/app", ROOT), "/mnt/hhvm"
        v.vm.synced_folder ".", "/vagrant", docker__exact: true
        
        v.vm.provider "docker" do |d|
            d.build_dir     = File.absolute_path("./hhvm", ROOT)
            d.name          = "vagrant-dockertest"
            d.cmd           = ["/sbin/my_init", "--enable-insecure-key"]
            #d.cmd           = ["/sbin/my_init", "--enable-insecure-key"]
            d.ports         = ["80:80"]
            #d.create_args   = ["-p", "127.0.0.1:49100:80"]
            #comment next line: https://github.com/mitchellh/vagrant/issues/3951#issuecomment-46939471
            #d.has_ssh   = true
            d.vagrant_vagrantfile = File.absolute_path("./Vagrantfile.proxy", ROOT)
        end
        
		#part below is not yet working
        ssh_key_path = File.absolute_path("./hhvm/insecure_key", ROOT)
        if File.directory?(ssh_key_path)
            v.ssh.username = "root"
            v.ssh.private_key_path = ssh_key_path
            v.ssh.port = 22
        end
        
        v.vm.boot_timeout = 300
    end
end

# PORT FORWARDING PROBLEMS:
# https://github.com/mitchellh/vagrant/issues/3728
# http://stackoverflow.com/a/23984537