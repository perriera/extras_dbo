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
 - [ ] Update/upgrade the system & add necessary support

		sudo apt update
		sudo apt upgrade 
		sudo apt autoremove
		sudo apt update
		sudo apt install git openssh-server -y
		sudo reboot 

 - [ ] Create your very own **git** account (and add a server directory)

		sudo adduser git
		sudo mkdir /srv/git
		sudo chown git:git /srv/git

 - [ ] Now change the name of your Ubuntu box to **gitserver**

		hostnamectl
		sudo hostnamectl set-hostname gitserver

 - [ ] Now in /etc/hosts change **ubuntu** to **gitserver**

		sudo vi /etc/hosts
		sudo reboot

 - [ ] When your back make sure the name was changed

		hostname

 - [ ] Now setup your client account to access your private server

		git config --global user.name “git”
		git config --global user.email “git@gitserver”

 - [ ] Now create an **.ssh** key and share it with the server

		ssh-keygen -t ed25519 -C “git@gitserver”
		cat ~/.ssh/id_ed25519.pub > /tmp/key.txt
		su git
		cd
		mkdir .ssh && chmod 700 .ssh
		touch .ssh/authorized_keys 
		chmod 600 .ssh/authorized_keys
		cat /tmp/key.txt > ~/.ssh/authorized_keys
		cat ~/.ssh/authorized_keys
		exit
		rm /tmp/key.txt 
		sudo systemctl restart ssh
		sudo systemctl status sshd

 - [ ] Now create your first project on your private git server

		su git
		cd /svr/git
		git init --bare xyzutil
		cd sample/hooks
		cp post-update.sample post-update
		exit

 - [ ] Now create an **dev** folder and clone your first project

		mkdir ~/dev
		cd ~/dev
		su git
		git clone git@gitserver:/srv/git/xyzutil.git

 - [ ] Now a file to it and push it into your private server
		 
		cd xyzutil
		echo “my test file” > file1.txt
		git add .; git commit -m "initial content"; 
		git push
		cd ..

 - [ ] Now check the git log for that project

		su git
		cd /srv/git/xyzutil
		git log
		exit

 - [ ] Now create a test directory and clone your project

		mkdir test
		cd test
		git clone git@gitserver:/srv/git/xyzutil.git
		cd xyzutil
		ls -la
		cd ../..
		rm -rf test
		
 - [ ] You now have an operational private GitHub server.

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

