![Icon_WithText](https://github.com/user-attachments/assets/e0fd54c8-7dd0-43d7-a579-8e2096b866cb)

Tip: Lindows 11.1 is not yet finished, this document only serves as a preview. Features may be added or removed at any time during the development process, please refer to the final product.

**Please validate the only official download address: https://github.com/happymimimix/Lindows_11.1-Post_Reset/releases**

**Anyone is allowed to make their own customized version of Windows based on Lindows 11.1, but they must clearly indicate in Readme that they are using my work and they must clearly inform the user that the file they are downloading is not the original Lindows 11.1 officially released by Happy_mimimix!**  

##

**NOTICE: Lindows 11.1 only supports legacy booting, any new devices must have legacy emulation enabled in BIOS setup and prioritize legacy booting in order to install Lindows 11.1 properly.** 

**Currently, I have no intention of supporting UEFI. Which is not only more difficult to modify, but also less reliable and compatible than Legacy. I did an experiment on the startup speed and obviously UEFI wasn't performing any better than legacy in my test. UEFI boots faster is just a busted myth!**

**If you insist on using UEFI, then I'm sorry that my original implementation of Lindows 11.1 can't meet your needs. You can take a look in [Forks](https://github.com/happymimimix/Lindows_11.1-Post_Reset/forks) to see if any third parties have ported this project to UEFI.**

##

# What's special about Lindows 11.1:

Are you frustrated with all those stuped restrictions in Windows?

No problem, I'll step in!

Lindows 11.1, developed by Happy_mimimix, is a mod of Windows 10 LTSC 2021 that completely removed all of the annoying restrictions in Windows. 

Providing the user absolute control over his/her device!

While having the simplicity and powerful software ecosystem of Windows, it also has the freedom and openness of Linux.

**Notice: This project has no relationship with Linspire!**

## Modifications:

## 1. Permanently disable of driver signature enforcement for REAL!
![Screenshot 2023-08-27 151259](https://github.com/Freedom-Windows-Team/Lindows_11.1/assets/143358583/b9d0a844-b753-42eb-a90a-f9f644e0f1fb)

An unsigned driver is not allowed to be installed? WTF is this?

This driver is 100% harmless. I said that!

Why won't it let me install it?

It is the most stupid thing in the world to assume that all programs that are not digitally signed are harmful in such a rude and irrational way.

On the other hand, are all signed drivers always safe?

I've never seen a more ignorant setup than this in my life.

I can't take it anymore, I want to crack this stuped thing immediately.

Although there have been quite a few tutorials on the internet about this tweak, the information never unite.

You can hardly find any two articles that follow the same steps, except for porting.

The worst part is that 90% of the articles are either outdated or simply have no effect at all.

I had no choice but to try all the relevant sources I could find one by one.

At the same time, it is also necessary to combine the contents of multiple articles, and in many cases, the key information that was omitted in one article can be added back in another.

After hundreds of hours of research and repeated experimenting, Lindows 11.1 is finally able to load any unsigned drivers and unsigned system kernel properly! 

During the process, I got more than 50 BSOD, stuck in bootstraps for more than 10 times, and I met no less than 20 times of "Preparing for automatic repair... "!

From now on, I am the boss of my computer! No one can ever stop me from loading any unsigned drivers.

## 2. Completely disable all integrity checks. FOR REAL! 

Check no more for the header checksum of the system kernel. 

Make no more verifications to the digital signature of system files. 

Always boot the machine regardless! 

## 3. Enable wifi hotspot at any time. Fully UNCONDITIONAL! 
![Screenshot 2023-08-27 161337](https://github.com/Freedom-Windows-Team/Lindows_11.1/assets/143358583/1982e92d-dd62-43ca-8bd9-15625470a8e5)
![Screenshot 2023-08-27 161246](https://github.com/Freedom-Windows-Team/Lindows_11.1/assets/143358583/e759a80c-bfc9-4a8f-8233-d8d5178f71d0)

I used to believe that a hotspot requires an internet connection in order to turn it on, until once I discovered by accident that the hotspot actually works as long as there was internet access at the moment it was turning on!

Once it's turned on already, disconnecting the network has no effect on the hotspot!

And after some research, I realized that this is actually an artificial restriction added by Microsoft.

What the fuck does it matter if the hotspot does not have an internet connection?

Can't I just play games and transfer files over the local area network?

I tried to use IDA to modify the system files, but found that the extremely complex code makes me unable to start.

After a lot of research, I finally found a little tool that can bypass this restriction and force the hotspot to be turned on!

A big thank you to My Public Wifi, developed by True Software, for making the breaking of this limitation possible! https://mypublicwifi.com/publicwifi/en/index.html

## 4. A super powerful never-downtime hotspot that can connect up to 128 devices! 
![image](https://github.com/Freedom-Windows-Team/Lindows_11.1/assets/143358583/8f5d0280-bbaf-431a-a4d9-af8faa030cf6)

After my continuous research, I finally managed to achieve a super powerful wifi hotspot that can connect up to 128 users by modifying the registry!

At the same time, I also completely disabled the idiot mechanism that automatically shuts down the hotspot when no one connects to it or when there is no internet access.

The hotspot will finish with Windows unless it is manually turned off!
As long as the computer is still on, the hotspot never disconnects!

## 5. Killing system processes without BSOD!
![image](https://github.com/Freedom-Windows-Team/Lindows_11.1/assets/143358583/2b5a0c71-caf5-46c0-8202-e5fd33ce94de)

Windows is dedicated to preventing users from killing critical system processes. 

You will get a BSOD as soon as you killed the process.

However, removing this restriction by modifying system files is not a good idea, because many batch creators like to use this method to manually trigger a BSOD.

This well-known quick one-click BSOD code makes use of this principle:
```
wmic process where name="wininit.exe" delete
wmic process where name="smss.exe" delete
wmic process where name="svchost.exe" delete
wmic process where name="csrss.exe" delete
```
So, if we completely destroy the mechanism that issues a BSOD when a system process are being killed, then all the batch code that makes use of this mechanism to achieve a manually triggered BSOD will all malfunction!

At the time I was stuck, the friendly 任务管理器TSK provides us with a very convenient gadget: Notcritical.exe! https://space.bilibili.com/102499223

It can be used to change a system process to an ordinary process, or change an ordinary process to a system process very easily.

Just use it to modify the process type, then you will be able to perfectly kill the system critical processes without getting a BSOD!

And at the same time, the batch code that achieves manual triggering the BSOD by killing the system processes also works properly.

## 6. RDP can remotely log in to accounts with no or empty passwords!

The option to enable remote login to accounts with no passwords or empty passwords with RDP via Group Policy has been implemented.

This option is available out-of-the-box and does not need to be set manually!

## 7. Install any unsigned UWP apps with just a double-click!

It is well known that you can install unsigned UWP apps via powershell command.
But this method is far too complicated.

Wouldn't it be better if we create a file association for it, and double-click on it will automatically call powershell to bypass the signature check?

## 8. Unsigned powershell scripts are allowed out of the box!
You can allow the execution of unsigned scripts by entering a command in powershell.
But it's very complicated and extremely tricky to set up. 

In order to simplify the process, I simply configured this option before the system is packaged, so that users can take a less complicated path.

## 9. Completely uninstall the pitiful Windows Defender!

windows defender never asks the user's opinion before dealing with dangerous programs and has a very high rate of false positives reporting!

What's more, uninstalling it is a pain in the ass!

After a lot of research, I finally found a methog to get rid of this fucking program!

Now we could finally get rid of it!

## 10. Strictly prohibit Lindows 11.1 from sending any debugging data to anyone without the user's awareness!

Windows 11 always likes to secretly send debugging data to various vendors in the background.
Without mentioning slowing down the system speed, such behavior is extremely disrespectful to the user's privacy!

If you use network surveillance software to monitor, you will discover that windows is secretly transferring a lot of data over the internet while you are not doing any web browsing at all!

Big thanks to The PC Security Channel for lifting the fog on this nifty little secret for the public and providing a great solution for this! https://youtu.be/IT4vDfA_4NI

## 11. Third party theme files can be loaded!

Broken the limit to third-party themes, which have paved the way for the 12th modification!

## 12. Premium system interface beautification!

Have the same freedom as Linux, but also have the same attractive system interface as Linux!

Big thanks to Rectify 11 for providing Lindows with an extremely stunning system theme. https://github.com/Rectify11/Installer

Thanks to WindowFX for giving Lindows 11.1 a very attractive window animation effect.

## 13. A super high efficiency comparable to Linux!

I have stripped down a lot of unnecessary components in windows which had imporved its efficiency dramatically.

There are only 61 active processes when the computer is idle, and the memory usage is only 1.3GB.

## 14. Better boot manager! 

A boot manager 100000x better than windows original. 

![image](https://github.com/happymimimix/Lindows_11.1-Post_Reset/assets/107282563/b8d19dfe-b0ad-49cd-80a7-56199b25251c)

# Software development related
**If you want to develop software for Lindows 11.1, please read this section carefully**

Doing software development in Lindows 11.1 is definitely going to be a lot easier than Windows, with a lot less annoying restrictions.

Especially for UWP and driver developers.

However, a side effect of this is that you will not be able to run your program on any other NT-based operating systems.

All customers that use your software will have to install Lindows 11.1 as well!

So, to prevent people from giving you feedback such as, "They've only made a UI for scamming, just forget about it", you need to make a special software installer that only works on Lindows.

# Notices

Before using Lindows 11.1, please make sure that you have basic manual malware removal capabilities!

In a system where all Windows's original security policies have been almost completely broken, Lindows 11.1 will have more security vulnerabilities than any other NT-based operating system.

Relying entirely on Huorong Internet Security(火绒安全软件) that comes with Lindows 11.1 is certainly not going to work.

How many of the computers in the world that have Windows installed are using Lindows 11.1?

Therefore, it is impossible for Huorong to make any preparations for the additional security vulnerabilities in Lindows 11.1!

You need to take care of these vulnerabilities yourself.

Not to mention that Lindows 11.1 didn't even exist when I embedded Huorong into Lindows 11.1!

If Huorong really wanted to do this adaptation, wouldn't it have to go with an internal beta version of Lindows 11.1 that was leaked in an unorthodox way?

.

Of course, this is not a problem that we need to be worried too much about before Lindows 11.1 becomes popularized to a certain extent.

As I said, how many computers in the world that have Windows installed are using Lindows 11.1?

Therefore, there won't be much hacker who is going to make a malware specifically for Lindows 11.1 in order to hack a single-digit number of Windows users.

**Note:** **When I say don't have to worry too much about it doesn't mean don't worry about it at all!!!**

.

**WARNING:** **Attention for gamers!**

Since Lindows 11.1 modifies many critical system files, this may cause you getting baned by anti-cheat systems in a number of games.

If you have any online games installed on your computer, be sure to test them now in a virtual machine to see how they work in Lindows 11.1 to prevent the unexpected!

Most single player games don't have very strict anti-cheat systems, so if you play a lot of single player games like I do then you can stop worrying about this.

# This is cool, but is it legal?

Lindows 11.1 did not modify anything related to Windows activation. 

You would still need a legit Windows 10 Pro product key to use Lindows. 

What Lindows has done is what Microsoft should've done. But they didn't, so we did it for them. 

This provides an additional choice for Windows users who cares about their freedom, and it does only just that. 

We never enforce people to install Lindows 11.1 on their device, and we make sure that anyone who uses Lindows is guaranteed to have a clear idea of what they are doing and have the ability to take good care of themselves. 

# How to install Lindows 11.1 on your own computer

**Note: I've written every step of the installation in detail to make it easier for people who never used Ghost before. So although the steps seem to be a lot, it's not really that complicated to follow.**

**In a nutshell, it's actually just these three steps: make a bootable USB flash drive, enable Legacy emulation in bios, and install Lindows 11.1.**

**For those who already know how to install an operating system on a computer with Symantec Ghost actually only need to read steps 12 to 15.**

1. Before you start, go to the Device Manager and look for the model of the various hardware used on your computer, especially for your network card and graphics card.
2. Google the corresponding driver installation package and place it anywhere except the C drive.
3. Install PowerISO.
4. Start Trial, but the Start Trial button has an annoying countdown timer and will not let you click it until 5 seconds after the software opens.
   To skip it, click Enter registration code, then click Continue trial version in the lower left corner of the enter registration code screen. 
5. Open the Lindows 11.1 installation image in PowerISO. 
6. Insert a blank USB flash drive.
7. Click Create Bootable USB Drive under Tools. 
8. Select your USB drive in Destination. 
9. Click Start in the lower right corner. 
10. Wait for the writing to complete.
11. Turn off your computer.
12. Press F2 at boot time to enter BIOS setup. 
13. Use your phone to search for how to enable Legacy Boot for your computer's brand. 
14. Follow the tutorial to enable Legacy Boot and configure it to use Legacy mode first. 
15. Turn the computer off.
16. Press F12 at boot time to access the boot menu.
17. Choose to boot from your USB flash drive. (Be careful to avoid any boot entries with the word UEFI in them!)

[TO DO]

28. Go to your desktop, open File Explorer and find the driver packages that you have downloaded.
29. Enjoy!

# Language Settings

The default display language of Lindows 11.1 is English, but it has a built-in Chinese language pack.

You don't need to download it separately, just simply adjust it in the settings and you can use it.

To set the language to Chinese, follow the steps below:

1. Press Win+R
2. Type ```ms-settings:```
3. Click on time and language on the left side.
4. Click on Language & region 
5. Select '中文（中华人民共和国）' in the Windows display language.
6. Log out and log in again 
7. Done

Switching to any other languages is done in the same way.

# Join us

If you want to join the development of Lindows 11.1, please come over [here](https://github.com/Freedom-Windows-Team/Lindows_11.1/discussions/1) to communicate with us.
