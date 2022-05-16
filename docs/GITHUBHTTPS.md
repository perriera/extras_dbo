## How to install your own GitHub Server onto Ubuntu 20.04
> Setting up a local git server requires an SSH server setup for two accounts setup first. One for the user and another for the server.

 1. **GIVEN** that a local GitHub server has better privacy capabilties
 2. **WHEN** we install the GitHub open source code
 3. **THEN** we can enjoy the benefits of a locally managed GitHub server

### Prerequisites
  - [How to install a Linux Platform (Ubuntu 20.04.4)](https://github.com/perriera/extras_oci/blob/dev/docs/UBUNTU.md)
  - A Ubuntu 20.04 installed [dedicated server](https://www.hostnextra.com/dedicated-server.html) or [KVM VPS](https://www.hostnextra.com/vps-hosting.html).
-   A root user access or normal user with administrative privileges.
-   Add DNS A record of your server’s hostname. 
- OpenSSH installed and running


### Wish Case
#### install git
 - [ ] Now copy and paste the following for a Linux environment

		sudo apt update
		sudo apt upgrade 
		sudo apt autoremove
		sudo apt update
		sudo reboot 

		sudo apt update
		sudo apt upgrade
		sudo apt update
		sudo apt upgrade 
		sudo apt update
		sudo apt upgrade 
		sudo apt update
		sudo apt upgrade 
		sudo apt upgrade
		sudo apt update
		sudo apt upgrade
		git
		sudo adduser git
		ls /home
		ls /home/git
		ls /home/git -la
		su git
		sudo mkdir /srv/git
		sudo chown git:git /srv/git
		sudo hostname gitserver
		hostname
		git config --global user.name “git”
		git config --global user.email “git@gitserver”
		ssh-keygen -t ed25519 -C “git@localhost”
		su git
		cat ~/.ssh/id_ed25519.pub > /tmp/key.txt
		su git
		ssh-keygen -t ed25519 -C “git@gitserver”
		su git
		cat ~/.ssh/id_ed25519.pub > /tmp/key.txt
		su git
		sudo systemctl restart ssh
		sudo systemctl status sshd
		mkdir ~/dev
		cd ~/dev
		su git
		git clone git@gitserver:/srv/git/sisutil.git 
		hostname
		sudo hostname gitserver
		hostname
		git clone git@gitserver:/srv/git/sisutil.git 
		hostname
		sudo hostname gitserver
		hostname
		sudo hostname gitserver
		hostname
		git clone git@gitserver:/srv/git/sisutil.git 
		hostnamectl
		hostname
		sudo hostnamectl set-hostname gitserver
		sudo vi /etc/hosts
		sudo reboot
		hostname
		cd dev
		ls
		cd sisutil/
		ls -la
		echo “my test file” > file1.txt
		git add .; git commit -m "Initial content"; git push
		cd ..
		mkdir t1
		cd t1
		git clone git@gitserver:/srv/git/sisutil.git 
		ls
		cd sisutil/
		ls
		cd ..
		rm -rf t1
		ls -la
		su git


		git@gitserver:~$ cat .bash_history 
		cd
		mkdir .ssh && chmod 700 .ssh
		touch .ssh/authorized_keys && chmod 600 .ssh/authorized_keys
		ls -la
		exit
		cat /tmp/key.txt >> ~/.ssh/authorized_keys
		cat ~/.ssh/authorized_keys
		exit
		cat /tmp/key.txt > ~/.ssh/authorized_keys
		cat ~/.ssh/authorized_keys
		exit
		ls /srv
		ls /srv/git/
		ls /srv/git/ -la
		cd /srv/git/
		git init --bare ~/sisutil.git
		rm -rf ~/sisutil.git
		git init --bare sisutil.git
		cd sisutil.git/
		cd hooks/
		cp post-update.sample post-update
		exit
		cd
		cd /srv/git
		ls -la
		cd sisutil.git/
		git log




### Alternate Case 
> **Do you have a DNS A record for your server’s hostname?** </br>
>	Use your DNS A record hostname wherever localhost is mentioned above. </br>
>Additional information on firewalls can be found in the external reference section (below)

### Summary 
Now you have an operational GitHub server running locally on your Ubuntu box. This should address the issue being encountered with CPM and public URLs.

### Next Steps
 - [How to setup your changelog.md](https://github.com/perriera/extras_oci/blob/dev/docs/CHANGELOG.md)

#### External References
- [How to install GITHUB on Ubuntu : Step by Step](https://linuxtechlab.com/how-to-install-github-on-ubuntu-step-by-step/)</br>
- [How to Setup Git Server on Ubuntu 20.04](https://linuxways.net/ubuntu/how-to-setup-git-server-on-ubuntu-20-04/)
- [How To Install and Enable SSH Server on Ubuntu 20.04](https://devconnected.com/how-to-install-and-enable-ssh-server-on-ubuntu-20-04/)
- [Ubuntu 20.04 SSH Server](https://linuxconfig.org/ubuntu-20-04-ssh-server)
- [How To Install and Configure GitLab on Ubuntu 18.04](https://www.digitalocean.com/community/tutorials/how-to-install-and-configure-gitlab-on-ubuntu-18-04)
- [Install and Configure Git Server on Ubuntu 20.04](https://www.hostnextra.com/kb/install-and-configure-git-server-on-ubuntu/)
https://github.com/cpm-cmake/CPM.cmake/issues/132
https://github.com/cpm-cmake/CPM.cmake/wiki/More-Snippets
https://github.com/cpm-cmake/CPM.cmake

