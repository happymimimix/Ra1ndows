# Lindows-Virtual-Machine-Checker
**This is a simple kernel mode driver that prevents people from installing Lindows 11.1 on a physical machine.**

With all signature verifications in Windows now completely removed in Lindows 11.1, this operating system is more likely to be infected by malwares than any other NT based operating systems. So, to protect inexperienced Windows users from being attacked, we've implemented this simple protection logic. 

If the current machine is not a virtual machine, it will immediately trigger a BSOD and prevent the user from reaching the desktop. 

However, that doesn't mean people cannot install Lindows 11.1 on a physical machine. It's actually extremely simple to hack this driver! 

I will not try to stop anyone from hacking this driver or posting tutorials online about how to hack this driver. I don't want to stop those who actually need Lindows 11.1 from using it.

For those who can't hack this driver, the odds are that they don't actually need to use Lindows 11.1 at all, and for those who really need Lindows 11.1, they will be able to find a way to hack this virtual machine detection mechanism very quickly. However, for spammers who just come along for the ride and newbies who are misled into hitting this page, this protection mechanism can be very effective in stopping these uninvolved people. 

If for some very rare odds you arrived at this page really wanted to have Lindows 11.1 on your hands so you can perform some tasks that was blocked by DSE, but also got stuck on hacking the virtual machine checker. You should go study more about how kernel mode drivers in windows works and why Microsoft implemented the Driver Signature Enforcement mechanism. You will know how to get around this virtual machine checker module by the time you have the ability required to take care of yourself and survive in Lindows 11.1. 
