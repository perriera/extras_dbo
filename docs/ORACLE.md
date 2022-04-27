

## How to setup Oracle Instant Client (on Linux, Windows or Mac)
> This is a basic step-by-step guide to how to successfully install the Oracle Instant Client on your Ubuntu instance. The material provided by Ubuntu is good and well researched but recent upgrades to Oracle Instant Client appear to need some refinements as listed in this article.

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
10. Execute **ls /usr/lib/oracle/(your version)**
11. You should see a directory called **client64**
12. The entire path is known as ORACLE_HOME
13. You must declare this environment variable in your .bashrc
14. Execute **vi ~/.bashrc** 
15. Append this to the end of the file:

		export ORACLE_HOME=/usr/lib/oracle/(your version)/client64
		export PATH=$PATH:$ORACLE_HOME/bin
		export LD_LIBRARY_PATH=$ORACLE_HOME/lib:${LD_LIBRARY_PATH}

16. In your case replace (your version) with the version you installed
17. Execute **sudo apt-get install libaio1**
18. Execute **source ~/.bashrc** 
19. Now test the client:

		sqlplus username/password@//dbhost:1521/SID

20. Output should be similar to the following:

		SQL*Plus: Release 19.0.0.0.0 - Production on Tue Apr 26 20:43:08 2022
		Version (your version).0.0.0
		Copyright (c) 1982, 2022, Oracle.  All rights reserved.
		Enter user-name:
21. Now to link up your *C++ include path* search:
	
		sudo ln -s /usr/include/oracle/(your version)/client64/ $ORACLE_HOME/include

22. In your CMakeLists.txt add ${ORACLE_INCLUDE} to any targets that need them

		target_include_directories(${TEST_EXEC} PUBLIC ${INCLUDES}  ${ORACLE_INCLUDE})

23. Now to link up your *C++ link  path* search:
24. In your CMakeLists.txt add **occi**  **chntsh** and **Threads::Threads** to any targets that need them

		target_link_libraries(${TEST_EXEC} PRIVATE ${PROJECT_NAME} stdc++fs extras occi clntsh Threads::Threads)

25. Execute **sudo vi /etc/ld.so.conf.d/oracle.conf** 
26. Add a single line */usr/lib/oracle/ your version /client64/lib/* 
27. Execute **sudo chmod o+r /etc/ld.so.conf.d/oracle.conf**
28. There is a quirk in the installation where by **libocci.so** has to be symbollically linked to the version that was actually installed, (oddly enough the symbolic link for **libchntsh.so** is already there)
29. Execute **sudo ln -s /usr/lib/oracle/(your version)/client64/lib/libocci.so.19.1 /usr/lib/oracle/(your version)/client64/lib/libocci.so**
30. Execute **sudo ldconfig** 
31. Now inside Visual Studio Code do a Ctrl-B and see a successful build
32. Then inside Visual Studio Code put a break point on a test case that uses *occi.h* (see *test_OracleSDK.cpp* and place a break point on line 43) and run the interactive debugger (aka. the green arrow next to *run-unittests*)
33. The program should compile, make, run and land on that break point.
34. In this project there is a file called FileOracle.cmake (which gets included in CMakeLists.txt. It may contain the following:

		set(ORACLE_HOME $ENV{ORACLE_HOME})
		set(ORACLE_INCLUDE "${ORACLE_HOME}/include")
		set(ORACLE_LIB "${ORACLE_HOME}/lib")
		set(ORACLE_BIN "${ORACLE_HOME}/bin")
		link_directories(BEFORE "${ORACLE_LIB}" )
35. The above are cmake 3.21 instructions that allow the CMake to be able to find the Oracle installation. It is all based on the value of ${ORACLE_HOME}. 


### Summary
> This shows the Oracle Instant Client has been installed successfully however you still need to see if the development portion is setup correctly. These instructions would be great if the entire process could be automated, but for now being able to install Oracle Instant Client at all with just the instructions in this markdown file is a milestone (as material on this process is rather sporatric across the Internet at this point in time).

### Next Steps
- How to setup Oracle Instant Client Development tools for C++17


