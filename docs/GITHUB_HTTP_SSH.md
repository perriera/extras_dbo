

## How to set up your own GitHub server to use ssh over http protocol (on Ubuntu 20.04)
> Now we have authenticated access through SSH and unauthenticated access through `git://`, but there is also a protocol that can do both at the same time. Setting up Smart HTTP is basically just enabling a CGI script that is provided with Git called `git-http-backend` on the server. This CGI will read the path and headers sent by a `git fetch` or `git push` to an HTTP URL and determine if the client can communicate over HTTP.

 1. **GIVEN** that your private GitHub server should be accessible via http
 2. **WHEN** we configure Ubuntu to load the git server as an apache server
 3. **THEN** we can access of private GitHub server over http 

### Prerequisites
- [How to set up your own GitHub server using git protocol (on Ubuntu 20.04)](https://github.com/perriera/extras_oci/blob/dev/docs/GITHUB_GIT.md)


### Wish Case
#### install git
 - [ ] Install Apache2 and apache utils 

		sudo apt-get install apache2 apache2-utils

 - [ ] Activate special hooks in apache to support git protocol [i]

		sudo a2enmod cgi alias env
		sudo systemctl start apache2
		sudo reboot

 - [ ] Now see if the server is running, open a browser (Firefox or better) and type as the url:

	 http://gitserver/


 - [ ] Give www-data access to /srv/git

		sudo chgrp -R www-data /srv/git www-data

*** THIS MAY REQUIRE adding user git to group 

 - [ ] Apache2 virtual host set up

		cd /etc/apache2/sites-available
		sudo cp 000-default.conf gitserver.com.conf
		sudo vi  gitserver.com.conf

 - [ ] Change gitserver.com.conf to this:

		<VirtualHost *:80>
			ServerName gitserver.com
			ServerAdmin webmaster@localhost
			DocumentRoot /srv/git
			ErrorLog ${APACHE_LOG_DIR}/error.log
			CustomLog ${APACHE_LOG_DIR}/access.log combined
			SetEnv GIT_PROJECT_ROOT /srv/git
			SetEnv GIT_HTTP_EXPORT_ALL
			ScriptAlias /git/ /usr/lib/git-core/git-http-backend/
			<Files "git-http-backend">
			    AuthType Basic
			    AuthName "Git Access"
			    AuthUserFile /srv/git/.htpasswd
			    Require valid-user
			</Files>
		</VirtualHost>

 - [ ] Add whatever usernames necessary to access the server over http:

		sudo htpasswd -c /srv/git/.htpasswd perry

 - [ ] Enable http for /srv/git and reload apache

		sudo a2ensite gitserver.com
		sudo a2dissite 000-default.conf
		sudo systemctl reload apache2

 - [ ] Test from client side

		cd ~/dev
		rm -rf test
		mkdir test
		cd test
		git clone http://gitserver/git/xyzutil.git

 - [ ] Do some modifications and push the updates using the credential of new created user

		cd xyzutil/
		cp file1.txt file1b.txt 
		git add .; git commit -m "test"; git push

 - [ ] You now have an operational private GitHub server (operating over http).

#### Footnotes
>[i] These 2 commands will install apache2 and also enables the `mod_cgi`, `mod_alias`, and `mod_env` modules, which are all needed for this to work properly.

### Alternate Case 
> **Want to add more projects?** </br>
>	Just like in the real github.com you need to create the project on the server first, (but the major difference here is that you use http protocol).</br>

	sh git
	cd /srv/git
	git init --bare (new project name).git
	cd (new project name).git/hooks
	cp post-update.sample post-update
	exit
	cd dev
	git clone http://gitserver/git/(new project name).git

### Summary 
Now that you have an operational GitHub server running locally on your Ubuntu box (as a standard Ubuntu service) you no longer have to add additional directory information. Hence, it now acts a lot more like the actual GitHub.com server (complete with a host name of your choosing).   

### Next Steps
- [How to set up your own GitHub server to use ssh over http protocol on Ubuntu 20.04](https://github.com/perriera/extras_oci/blob/dev/docs/GITHUB_HTTP_SSH.md)
 - [How to setup your changelog.md](https://github.com/perriera/extras_oci/blob/dev/docs/CHANGELOG.md)
- https://cloud.redhat.com/blog/private-git-repositories-part-2a-repository-ssh-keys
- https://nurdletech.com/linux-notes/ssh/via-http.html
- https://infra.apache.org/user-ssh
- http://www.beginninglinux.com/home/server-administration/apache/enable-ssh-after-fresh-apache2-or-lamp-install





