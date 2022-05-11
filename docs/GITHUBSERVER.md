


## How to install the tools necessary for C++11/17 projects
> In this step we need to install all the tools used by this project (that you may or may not already have installed.

 1. **GIVEN** we need to have C++17, cmake 3.2.1, pip installed
 2. **WHEN** we follow the instructions listed here
 3. **THEN** we can press Ctrl-B inside Visual Studio Code

### Prerequisites
  - [How to install a Linux Platform (Ubuntu 20.04.4)](https://github.com/perriera/extras_oci/blob/dev/docs/UBUNTU.md)
  - A Ubuntu 20.04 installed [dedicated server](https://www.hostnextra.com/dedicated-server.html) or [KVM VPS](https://www.hostnextra.com/vps-hosting.html).
-   A root user access or normal user with administrative privileges.
-   Add DNS A record of your server’s hostname. 

#### External References
- [How to install GITHUB on Ubuntu : Step by Step](https://linuxtechlab.com/how-to-install-github-on-ubuntu-step-by-step/)</br>
- [How to Setup Git Server on Ubuntu 20.04](https://linuxways.net/ubuntu/how-to-setup-git-server-on-ubuntu-20-04/)
- [How To Install and Enable SSH Server on Ubuntu 20.04](https://devconnected.com/how-to-install-and-enable-ssh-server-on-ubuntu-20-04/)
- [Ubuntu 20.04 SSH Server](https://linuxconfig.org/ubuntu-20-04-ssh-server)
- [How To Install and Configure GitLab on Ubuntu 18.04](https://www.digitalocean.com/community/tutorials/how-to-install-and-configure-gitlab-on-ubuntu-18-04)
- [Install and Configure Git Server on Ubuntu 20.04](https://www.hostnextra.com/kb/install-and-configure-git-server-on-ubuntu/)

### Wish Case
Now that you have your project cloned we need to make sure you have the tools necessary to compile properly:
#### install git
 - [ ] Now copy and paste the following for a Linux environment

		sudo apt update -y
		sudo apt install git openssh-server -y

 - [ ] Verify it's installation

		git --version

#### configure server side git
 - [ ] Add user to handle the repositories:

		sudo adduser git
		
 - [ ] Log in as a git user
		
		su – git

 - [ ] Initiate a new empty repository using following command:

		git init –bare ~/hostnextra.git

 - [ ] Enable post-update hook by copying the sample file as follows:

		cd hostnextra.git/hooks/
		cp post-update.sample post-update

#### configure client side ssh

- [ ] Configure for localhost

		git config –global user.name “git”  
		git config –global user.email “git@localhost”

- [ ] Create a key

		ssh-keygen -t ed25519 -C “git@localhost”

- [ ] Now copy the public key to where it can be copied
 
		 cat ~/.ssh/id_ed25519.pub > ~/key.txt
  

#### configure server side ssh

- [ ] To create the SSH directory and file for holding the authorized ssh key for git user, run the following commands:

		mkdir -p ~/.ssh
		chmod 700 ~/.ssh
		touch ~/.ssh/authorized_keys
		chmod 600 ~/.ssh/authorized_keys

- [ ] now add the key.txt created above
 
		 cat /home/**your home**/key.txt >> ~/.ssh/authorized_keys

- [ ] now restart ssh

		sudo systemctl restart ssh
		sudo systemctl status sshd

- [ ] now exit (or open another terminal window)

		exit 

#### configure client side git

- [ ] Create a directory where you can keep all your projects

		mkdir ~/dev
		cd ~/dev
		
- [ ] Now, create a clone the hostnextra.git repository that we have created earlier in the server

		git clone git@localhost:~/hostnextra.git hostnextra.git

- [ ] Go to respository

		cd hostnextra.git

- [ ] You can see the repository is empty, so lets create some files

		echo “my test file” > file1.txt

- [ ] Add these file to our git repository

		git add .
		git commit -m "update"

- [ ] Push these changes to the remote git repository at localhost

		git push origin master

- [ ] Verify the changes, access the git server and run following command to check the logs

		cd ~/hostnextra.git
		git log
		


### Alternate Case 
> **No DNS A record of your server’s hostname?** </br>
>	Use your server IP address in the place of hub.hostnextra.com.</br>
>(aka. *127.0.0.1* or *localhost*)

### Summary 
Now you have instaled the development environment and editor for a C++17 project (complete with cmake 3.21 support). The next steps are now to clone the project then setup your changelog.md (for accurate version control).

### Next Steps
 - [How to generate a new SSH key for your GitHub.com account](https://github.com/perriera/extras_oci/blob/dev/docs/SSHKEY.md)
 - [How to clone your project (with this template)](https://github.com/perriera/extras_oci/blob/dev/docs/CLONE.md)
 - [How to setup your changelog.md](https://github.com/perriera/extras_oci/blob/dev/docs/CHANGELOG.md)


