
## How to set up your own GitHub server using git protocol (on Ubuntu 20.04)
> Now let’s set up a daemon serving repositories using the “Git” protocol. This is a common choice for fast, unauthenticated access to your Git data. Remember that since this is not an authenticated service, anything you serve over this protocol is public within its network.

 1. **GIVEN** that your private GitHub server should be a service
 2. **WHEN** we configure Ubuntu to load the git server as a service
 3. **THEN** we can support other features such as git over http 

### Prerequisites
- [How to set up your own GitHub server using ssh protocol (on Ubuntu 20.04)](https://github.com/perriera/extras_oci/blob/dev/docs/GITHUB_SSH.md)


### Wish Case
#### install git
 - [ ] First, run gitserver directly to see if it works

		git daemon --base-path=/srv/git --export-all --enable=receive-pack --reuseaddr --informative-errors --verbose

 - [ ] The words "Ready to rumble" should appear:

		[XXXX] Ready to rumble

 - [ ] Now open another terminal box and test it:

		cd dev
		mkdir test
		cd test
		git clone git://gitserver/project.git

xxx

		sudo apt update
		sudo apt upgrade 
		sudo apt autoremove
		sudo apt update
		sudo apt install git openssh-server -y
		sudo reboot 

 - [ ] Create your very own **git** account (and add a server directory)

		sudo adduser git

 - [ ] Added a dedicated git server directory

		sudo mkdir -p /srv/git
		sudo chown git:git /srv/git

 - [ ] Now change the name of your Ubuntu box to **gitserver**

		hostnamectl
		sudo hostnamectl set-hostname gitserver

 - [ ] Now in /etc/hosts change **ubuntu** to **gitserver**

		sudo vi /etc/hosts

 - [ ] Now reboot to make sure the changes were made

		sudo reboot

 - [ ] When your back make sure the name was changed

		hostname

 - [ ] Now setup your client account to access your private server

		git config --global user.name “git”
		git config --global user.email “git@gitserver”

 - [ ] Now create an **.ssh** key and share it with the server

		ssh-keygen -t ed25519 -C “git@gitserver”

 - [ ] Now add that key to the **git** user account

		cat ~/.ssh/id_ed25519.pub > /tmp/key.txt

 - [ ] Now log into the **git** user account

		su git

 - [ ] Now configure the **git** user account

		cd
		mkdir .ssh && chmod 700 .ssh
		touch .ssh/authorized_keys 
		chmod 600 .ssh/authorized_keys
		cat /tmp/key.txt > ~/.ssh/authorized_keys
		cat ~/.ssh/authorized_keys
		exit
		rm /tmp/key.txt 

- [ ] Now activate sudo mode again

		sudo ls

- [ ] Now restart ssh

		sudo systemctl restart ssh
		sudo systemctl status sshd

 - [ ] Now log into the **git** user account

		su git

 - [ ] Now create your first project on your private git server

		cd /srv/git
		git init --bare xyzutil.git
		cd xyzutil.git/hooks
		cp post-update.sample post-update
		exit

 - [ ] Now create an **dev** folder and clone your first project

		mkdir ~/dev
		cd ~/dev
		git clone git@gitserver:/srv/git/xyzutil.git

 - [ ] Now a file to it and push it into your private server
		 
		cd xyzutil
		echo “my test file” > file1.txt
		git add .; git commit -m "initial content"; 
		git push
		cd ..

 - [ ] Now log into the **git** user account

		su git

 - [ ] Now check the git log for that project

		cd /srv/git/xyzutil.git
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
> **The words "Ready to rumble" didn't appear**</br>
>	Check your parameters and look up on the Internet for possible reasons why. But if you followed the directions from the previous How-to and you are using the same version, the given parameters should world </br>

### Alternate Case 
> **Wanna add more users?** </br>
>	Just get the ssh pub key of others , then append it to /home/git/.ssh/authorized_keys</br>

	cat Jack_id_rsa.pub | ssh git@gitserver "cat >> /home/git/.ssh/authorized_keys"

### Alternate Case 
> **Wanna disable shell login for user account git?** </br>
>	You should note that currently all these users can also log into the server and get a shell as the `git` user. If you want to restrict that, run below command on git server.</br>

	sudo chsh git -s $(which git-shell)

### Summary 
Now you have an operational GitHub server running locally on your Ubuntu box. This should address the issue being encountered with CPM and public URLs.

### Next Steps
- [How to set up your own GitHub server using git protocol on Ubuntu 20.04](https://github.com/perriera/extras_oci/blob/dev/docs/GITHUB_GIT.md)
- [How to set up your own GitHub server using http protocol on Ubuntu 20.04](https://github.com/perriera/extras_oci/blob/dev/docs/GITHUB_HTTP.md)
 - [How to setup your changelog.md](https://github.com/perriera/extras_oci/blob/dev/docs/CHANGELOG.md)

#### External References
- [How to install GITHUB on Ubuntu : Step by Step](https://linuxtechlab.com/how-to-install-github-on-ubuntu-step-by-step/)</br>
- [How to Setup Git Server on Ubuntu 20.04](https://linuxways.net/ubuntu/how-to-setup-git-server-on-ubuntu-20-04/)
- [How To Install and Enable SSH Server on Ubuntu 20.04](https://devconnected.com/how-to-install-and-enable-ssh-server-on-ubuntu-20-04/)
- [Ubuntu 20.04 SSH Server](https://linuxconfig.org/ubuntu-20-04-ssh-server)
- [How To Install and Configure GitLab on Ubuntu 18.04](https://www.digitalocean.com/community/tutorials/how-to-install-and-configure-gitlab-on-ubuntu-18-04)
- [Install and Configure Git Server on Ubuntu 20.04](https://www.hostnextra.com/kb/install-and-configure-git-server-on-ubuntu/)
- https://github.com/cpm-cmake/CPM.cmake/issues/132
- https://github.com/cpm-cmake/CPM.cmake/wiki/More-Snippets
- https://github.com/cpm-cmake/CPM.cmake
- [Verifying the Authenticity of a Remote Server through Its SSH Key Fingerprint](https://www.linode.com/docs/guides/verifying-the-authenticity-of-remote-host/)
- https://ubuntututorials.org/set-up-private-git-server-ubuntu-2004/

- https://www.andrewhoog.com/post/howto-setup-a-private-git-server-on-ubuntu-18.04/

- https://www.linux.com/training-tutorials/how-run-your-own-git-server/

- https://git-scm.com/book/en/v2/Git-on-the-Server-Setting-Up-the-Server

- https://git-scm.com/book/en/v2/Git-on-the-Server-Git-Daemon

- https://linuxways.net/ubuntu/how-to-setup-git-server-on-ubuntu-20-04/

  

- https://yunwuxin1.gitbooks.io/git/content/en/17950f608975b8c96cebaaa17b3904d1/a5209e0c593176dd3285b76799bafb1f.html
