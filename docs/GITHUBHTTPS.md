
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


