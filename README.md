HHVM-Vagrant-Docker
===================

HHVM try-out with vagrant and docker for virtualization

Dependencies:
- Virtualbox 4.3.12 or higher https://www.virtualbox.org/wiki/Downloads
- Vagrant 1.6.3 or higher https://www.vagrantup.com/downloads.html
- Rsync
    - Windows: http://www.rsync.net/resources/howto/windows_rsync.html
    - OSX: http://blog.brettalton.com/2013/08/05/how-to-speed-up-rsync-on-your-mac-and-stop-the-dreaded-building-file-list/

Vagrant
=======

Bring docker container up with:
```bash
vagrant up hhvm --provider=docker
```

Provision box with:
```bash
vagrant reload --provision
```

Credits
=======
- See https://github.com/nikolaplejic/docker.hhvm for docker image inspiration
- See http://stackoverflow.com/a/23984537 for vagrant proxy inspiration
- See https://www.vagrantup.com/blog/feature-preview-vagrant-1-6-docker-dev-environments.html for vagrant inspiration
