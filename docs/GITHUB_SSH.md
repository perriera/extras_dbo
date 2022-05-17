
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
		git clone git://gitserver/xyzutil.git

 - [ ] That should have resulted in:

		Cloning into 'xyzutil'...
		remote: Enumerating objects: 3, done.
		remote: Counting objects: 100% (3/3), done.
		remote: Total 3 (delta 0), reused 0 (delta 0)
		Receiving objects: 100% (3/3), done.

 - [ ] Now to add this as a service (stop the other terminal) and add this to **systemd**:

		sudo vi /etc/systemd/system/git-daemon.service

 - [ ] In that file add the following (if you had to modify the daemon parameters adjust as necessary):

		[Unit]
		Description=Start Git Daemon

		[Service]
		ExecStart=/usr/bin/git daemon --base-path=/srv/git --export-all --enable=receive-pack --reuseaddr --informative-errors --verbose

		Restart=always
		RestartSec=500ms

		StandardOutput=syslog
		StandardError=syslog
		SyslogIdentifier=git-daemon

		User=git
		Group=git

		[Install]
		WantedBy=multi-user.target

 - [ ] Now enter the following to enable the service:

		sudo systemctl enable git-daemon
		sudo reboot

 - [ ] Now test your private GitHub server (using git protocol):

		cd dev
		rmdir -rf test
		mkdir test
		cd test
		git clone git://gitserver/xyzutil.git
		
 - [ ] You now have an operational private GitHub server (as a standard Ubuntu service).

### Alternate Case 
> **Starting and stopping the daemon manually**</br>
>	As per standard Ubuntu/Linux service commands: </br>

	sudo systemctl start git-daemon
	sudo systemctl stop git-daemon

### Summary 
Now you have an operational GitHub server running locally on your Ubuntu box (as a standard Ubuntu service). 

### Next Steps
- [How to set up your own GitHub server using http protocol on Ubuntu 20.04](https://github.com/perriera/extras_oci/blob/dev/docs/GITHUB_HTTP.md)
 - [How to setup your changelog.md](https://github.com/perriera/extras_oci/blob/dev/docs/CHANGELOG.md)



