HHVM-Vagrant-Docker
===================

HHVM try-out with vagrant and docker for virtualization

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
