![Icon_WithText](https://github.com/user-attachments/assets/e0fd54c8-7dd0-43d7-a579-8e2096b866cb)

# News: 
**12/18/2023 -** OHHHHHHHHHHHHHHH! dnmx.org is back online again! YAY! I'm finally able to recieve emails at FreedomWindows@dnmx.org again! I'm back everyone! 

**12/08/2023 -** dnmx.org is shutting down, I can no longer access my email FreedomWindows@dnmx.org. 
This is probably my last visit here, bye guys. 
I will later on invite my other account as a contributor to this project to keep it going. 

**12/07/2023 -** For better secrity, we are assigning @114514NotAvailable a job to make a system integrity checker that is 100x better than the one built-in in windows for us. Including a fully automatic repair function that repairs corrupted system files once they are found. The integrity checker can be disabled at anytime by simply writing a registry value, not like the windows built in one that doesn't provide a disable option at all. And, best of all, this integrity checker is open sourced and the hard coded checksum values can be easily modified to keep your own mod of Lindows 11.1 safe! 
The user will be notifyed if the integrity checker has been customized or fully disabled everytime they login, this notification cannot be disabled. Otherwise it leave oppertunity for malwares to secreatly disable this integrity checker, or even just compile their own ones from source that reports 'success' no matter what, all done without the user noticing anything. I'm sorry to say that we're going to heavly protect this integrity checker so Lindows 11.1 can be ready for productivity instead of just being a experimenting OS. This is the only module in the system that you can't temper with. If you've got any special requirements, please send an email to 114514NotAvailable@protonmail.com with detailed explaination of what you're trying to do. After we've reviewed your request, we will privately mail you a customized image without the integrity checker that you are strongly prohibited from sharing it with anyone. 

**12/07/2023 -** We are now experimenting a method to destroy the PE checksum verification on windows 11, hopefully we can get it done soon so Lindows 11.1 can be released. 

**12/07/2023 -** @114514NotAvailable joined the development of this project! 

**12/07/2023 -** @sudo-000 joined the development of this project! 

**10/09/2023 -** Things are taking longer than expected, very sorry to whom waiting for Lindows 11.1 to come out. I have under estimated the complexity of this project. Please be patient, freedom of choice will come to you eventually! 

**09/03/2023 -** Almost ready! We've successfully made every components on Lindows 11.1 working well, it's now time for assembling them together and pack everything into a working ISO installation image! 

# **Lindows 11.1** 

Tip: Lindows 11.1 is not yet finished, this document only serves as a preview. Features may be added or removed at any time during the development process, please refer to the final product.

**Please validate the only official download address: https://github.com/happymimimix/Lindows_11.1-Post_Reset/releases**

**Anyone is allowed to make their own customized version of Windows based on Lindows 11.1, but they must clearly indicate in Readme that they are using my work and they must clearly inform the user that the file they are downloading is not the original Lindows 11.1 officially released by Happy_mimimix!**  

##

**NOTICE: Lindows 11.1 only supports legacy booting, any new devices must have legacy emulation enabled in BIOS setup and prioritize legacy booting in order to install Lindows 11.1 properly.** 

**Currently, I have no intention of supporting UEFI. Which is not only more difficult to modify, but also less reliable and compatible than Legacy. I did an experiment on the startup speed and obviously UEFI wasn't performing any better than legacy in my test. UEFI boots faster is just a busted myth!**

**If you insist on using UEFI, then I'm sorry that my original implementation of Lindows 11.1 can't meet your needs. You can take a look in [Forks](https://github.com/happymimimix/Lindows_11.1-Post_Reset/forks) to see if any third parties have ported this project to UEFI.**

##

# Main part:

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

Many thanks to all netizens who helped me with this!

Fangyzhai：
http://bbs.wuyou.net/forum.php?mod=viewthread&tid=433012
(most helpful!!!)

菜菜:
https://zhuanlan.zhihu.com/p/590181211

金典教授:
https://www.bilibili.com/read/cv20303238/

hfiref0x's UPGDSED open source project:
https://github.com/hfiref0x/UPGDSED/blob/master/src/main.c

Computernewb Wiki:
https://computernewb.com/wiki/How_to_debomb_Windows_10/Server_2016_betas

2013goldenegg:
http://bbs.wuyou.net/forum.php?mod=viewthread&action=printable&tid=298603

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

I was on fire immediately, what does it matter if the hotspot does not have an internet connection?

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

So, to prevent people from giving you feedback such as, "They've only made a UI for scamming, just forget about it", you need to add a detection module to the installer.

If it detects that the user is not using Lindows 11.1, it will automatically open this Github repository and direct the user to download and install the correct operating system to run your software. 

**Note:** **Heads up, the following content is very important!**

In Lindows 11.1, installation packages for applications are stored in *.BAT format.

To make such an installation package, follow these steps:

1. Compress your software into one or more *.zip archives.
2. Right-click on this zip archive and find the Convert to BAT option in the Send to... menu. 
3. In the dark blue background window that pops up, check the Long Lines box, uncheck everything else, and then click OK.
4. Right click on the generated BAT file and select Edit, you will see the following code:
   ![image](https://github.com/Freedom-Windows-Team/Lindows_11.1/assets/143358583/825a701b-e2ab-421b-b8cf-1a191585ad81)
5. Add ```Powershell Expand-Archive -LiteralPath [zip file name] -DestinationPath [decompression path]``` to the third line.
6. To add the Lindows detector, insert the following code after the first line:
```
Detection module not yet complete
```
7. If necessary, you can perform actions such as creating a start menu shortcut, control panel uninstall entry, etc. after the third line.
```
Uninstall entry in control panel：
REG ADD "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Program_ID" /v DisplayName /t REG_SZ /d "My Program" /f
REG ADD "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Program_ID" /v DisplayVersion /t REG_SZ /d "v1.0" /f
REG ADD "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Program_ID" /v UninstallString /t REG_SZ /d "C:\Path\To\Uninstaller.bat" /f
REG ADD "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Program_ID" /v DisplayIcon /t REG_SZ /d "C:\Path\To\Icon.ico" /f
REG ADD "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Program_ID" /v NoModify /t REG_DWORD /d 0 /f
REG ADD "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Program_ID" /v ModifyPath /t REG_SZ /d "C:\Path\To\RepairTool.bat" /f
```
```
Add shortcut：
Method 1：
echo.[InternetShortcut] >"C:\ProgramData\Microsoft\Windows\Start Menu\Programs\My Program\Program.URL"
echo.URL=C:\Path\To\Program.exe >>"C:\ProgramData\Microsoft\Windows\Start Menu\Programs\My Program\Program.URL"
echo.IconIndex=0 >>"C:\ProgramData\Microsoft\Windows\Start Menu\Programs\My Program\Program.URL"
echo.IconFile=C:\Path\To\Program.exe >>"C:\ProgramData\Microsoft\Windows\Start Menu\Programs\My Program\Program.URL"
Method 2：
mklink "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\My Program\Program.exe" "C:\Path\To\Program.exe"

```

Batch scripts about repairing and uninstalling can be converted using the ECHO generator tool in the 快速启动 menu in Ibat at the top. (You can find Ibat in the start menu)

Use Notepad++ to find and replace ```&@ECHO.``` with ```>>"C:\Path\To\Uninstaller.bat"&@ECHO.```.

Replace the first ```>>"C:\Path\To\Uninstaller.bat"&@ECHO.``` that appears in the file with ```>"C:\Path\To\Uninstaller.bat"&@ECHO.```.

Add ```>>"C:\Path\To\Uninstaller.bat"``` to the end of the file, with a caution not to break lines.

Subsequently, just paste the code directly into the installer.

Note that there is a limit on the length of a single line of text in the batch program, and the part that exceeds the limit will not be read by CMD.

If you can't write back properly after conversion, please try to replace all ```&@ECHO.``` with ```\n@ECHO.```.

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

Therefore, not a single idiot hacker is going to design a malware specifically for Lindows 11.1 in order to hack a single-digit number of Windows users.

**Note:** **When I say don't have to worry too much about it doesn't mean don't worry about it at all!!!**

.

**WARNING:** **Attention for gamers!**

Since Lindows 11.1 modifies many critical system files, this may cause you getting baned by anti-cheat systems in a number of games.

If you have any online games installed on your computer, be sure to test them now in a virtual machine to see how they work in Lindows 11.1 to prevent the unexpected!

Most single player games don't have very strict anti-cheat systems, so if you play a lot of single player games like I do then you can stop worrying about this.

# This is cool, but is it legal?

To avoid copyright related issues, this project will be released as a patch and will not modify any windows activation related content.

Microsoft created Windows, so Microsoft holds the copyright to Windows, which I won't violate.

But the copyright of this patch, is mine!

The way to apply the patch is as follows:

First go [here](https://archive.org/download/windows-11_21h2-22000-318/Windows%2011.iso) to download the official original Microsoft Windows 11 21H1 installation image.

Download the latest Lindows 11.1 patch from the release section.

Place the original windows 11 iso in the same directory with Patch.bat and execute Patch.bat.

After a while, you will obtain the full Lindows 11.1 installation image.

# How to install Lindows 11.1 on your own computer

**Note: I've written each step of the installation in detail to make it easier for newbies who haven't had much time with computers. So although the steps seem to be a lot, it's not really complicated to follow.**

**In a nutshell, it's really just three steps: make a bootable USB flash drive, enable Legacy emulation, and install Lindows 11.1.**

**For those who already know how to install an operating system on a computer on their own actually only need to read steps 12 to 15.**

## Method 1: Fresh Installation (Recommended)

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
18. When you see "Press any key to boot from CD/DVD...", press any key on your keyboard immediately.
    It doesn't matter which key you press, but something must be pressed, and before this text disappears!
19. If all of the above steps have been performed correctly, you will see four blue squares in the center of the screen and a small white circle spinning underneath.
    If you see your computer's manufacturer's logo, that means you did something wrong in step 14.
20. Wait a few moments and you will be taken to the system installation screen.
21. Click Next.
22. If you have a Windows 11 Pro key, enter it. Otherwise, click "I don't have a product key" in the lower right corner.
23. Click Custom.
24. Locate the partition where your C drive is located and delete it.
25. Locate the System Reserved partition (if any) and click Delete.
26. Locate the Recovery partition (if any) and click Delete.
27. Select "Unallocated Sapce" and click Next to start the installation.
    In some cases, an installation error may occur.
    Don't worry, reboot your computer and repeat the process from step 15 and you will be able to resolve 90% of these installation errors.
28. Go to your desktop, open File Explorer and find the driver packages that you have downloaded.
29. Enjoy!

## Option 2: Upgrade from Windows to Lindows 11.1

1. Follow the fresh install tutorial above from step 3 and stop after step 22.
2. Click Upgrade.
3. Wait for the installation to complete.
4. Enjoy!

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

# Image size issues

You've claimed to simplify windows by removing unnecessary components, but why is the size of the Lindows iso even larger than the original?
A backward simplification?

In order to save time downloading language packs and input methods. 
Lindows 11.1 has got all language packs and font files for all the languages provided in windows built-in, just like macOS.

In addition to that, we have embedded quite a few third-party applications, resulting in a file size that is even larger than the original. 

However, unlike Microsoft's approach of bundling software, we were extremely conscious of the cleanliness of our system.

The apps that I think are great but not everyone in the world needs, will be available as installers in the system.

They just stay there quietly, not asking no answering. 
But once you ask, they'll immediately respond!

Moreover, it supports batch removal with a single click, so users don't need to manually click on them one by one to remove them.

Isn't it convenient?

If needed, you can leave a message in [discussions](https://github.com/Freedom-Windows-Team/Lindows_11.1/discussions) to ask me for a compact version of Lindows 11.1 image.

# Join us

If you want to join the development of Lindows 11.1, please come over [here](https://github.com/Freedom-Windows-Team/Lindows_11.1/discussions/1) to communicate with us.
