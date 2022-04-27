
## How to setup Oracle Instant Client (on Linux, Windows or Mac)
> This is a basic step-by-step guide to how to successfully install the Oracle Instant Client on your Ubuntu instance. The material provided by Ubuntu is good well researched but recent upgrades to Oracle Instant Client appear to need some refinements as listed in this article.

 1. GIVEN we need to support apps that need Oracle database support
 2. WHEN we install the Oracle Instant Client
 3. THEN we will have access to a Oracle database

### Prerequisites

- [How to setup a development environment (on Linux, Windows or Mac)](https://github.com/perriera/extras_oci/blob/dev/docs/ENVIRONMENT.md)
- [How to install the tools necessary for C++11/17 projects](https://github.com/perriera/extras_oci/blob/dev/docs/INSTALL.md)
- [How to clone your project (with this template)](https://github.com/perriera/extras_oci/blob/dev/docs/CLONE.md)
- [How to setup your changelog.md](https://github.com/perriera/extras_oci/blob/dev/docs/CHANGELOG.md)

### Resources
[Ubuntu documentation: Oracle Instant Client](https://help.ubuntu.com/community/Oracle%20Instant%20Client)

### Wish Case

 1. Go to [Oracle Instant Client](https://help.ubuntu.com/community/Oracle%20Instant%20Client) and download a specific version of Oracle Instant Client
 2. Select either *Basic* or *Basic Lite* (just one)
 3. Download all supporting .rpm files for everything under that specific version
 4. Open a Terminal box 
 5. Execute **sudo apt-get install alien**
 6. Execute **cd ~/Downloads**
 7. Using the alien installer install each of the .rpm files.
 8. (aka. in this case version 12 was downloaded)

		sudo alien -i oracle-instantclient12.1-basic-12.1.0.2.0-1.x86_64.rpm
		sudo alien -i oracle-instantclient12.1-sqlplus-12.1.0.2.0-1.x86_64.rpm
		sudo alien -i oracle-instantclient12.1-devel-12.1.0.2.0-1.x86_64.rpm

7. As soon as those are completed 
8. Execute **ls /usr/lib/oracle**
9. You should see a number, (it should be the version number you selected for install)
10. Execute **ls /usr/lib/oracle/_version_**
11. You should see a directory called **client64**
12. The entire path is known as ORACLE_HOME
13. You must declare this environment variable in your .bashrc
14. Execute **vi ~/.bashrc** 
15. Append this to the end of the file:

		export ORACLE_HOME=/usr/lib/oracle/12.1/client64
		export PATH=$PATH:$ORACLE_HOME/bin
		export LD_LIBRARY_PATH=$ORACLE_HOME/lib:${LD_LIBRARY_PATH}

16. In your case use the version number you installed instead of the *12.1*
17. Execute **sudo apt-get install libaio1**
18. Execute **source ~/.bashrc** 
19. Now test the client:

		sqlplus username/password@//dbhost:1521/SID

20. Output should be similar to the following:

		SQL*Plus: Release 19.0.0.0.0 - Production on Tue Apr 26 20:43:08 2022
		Version 19.15.0.0.0
		Copyright (c) 1982, 2022, Oracle.  All rights reserved.
		Enter user-name:
21. Now to link up your *C++ include path search*:
	
		sudo ln -s /usr/include/oracle/19.15/client64/ $ORACLE_HOME/include

In your CMakeLists.txt add ${ORACLE_INCLUDE} to any targets that need them

		target_include_directories(${TEST_EXEC} PUBLIC ${INCLUDES}  ${ORACLE_INCLUDE})

22. Now to link up your *C++ link  path search*:
23. In your CMakeLists.txt add **occi**  **chntsh** and **Threads::Threads** to any targets that need them

		target_link_libraries(${TEST_EXEC} PRIVATE ${PROJECT_NAME} stdc++fs extras occi clntsh Threads::Threads)

24. Execute **sudo vi /etc/ld.so.conf.d/oracle.conf** 
25. Add a single line */usr/lib/oracle/_version_/client64/lib/* 
26. Execute **sudo chmod o+r /etc/ld.so.conf.d/oracle.conf**
27. Execute **sudo ln -s /usr/lib/oracle/19.15/client64/lib/libocci.so.19.1 /usr/lib/oracle/19.15/client64/lib/libocci.so**
28. Execute **sudo ldconfig** 
29. Now inside Visual Studio Code do a Ctrl-B and see a successful build
30. Then inside Visual Studio Code put a break point on a test case that uses *occi.h* (see *test_OracleSDK.cpp* and place a break point on line 43) and run the interactive debugger (aka. the green arrow next to *run-unittests*)
31. The program should compile, make, run and land on that break point.


### Summary
> This shows the Oracle Instant Client has been installed successfully however you still need to see if the development portion is setup correctly.

### Next Steps
- How to setup Oracle Instant Client Development tools for C++17


