---
layout: post
title:  "REACT NATIVE WITHOUT ANDROID STUDIO"
date:   2021-06-04 21:12:59 +0700
author: "Akhmal R"
categories: english article
---

# Setting up React Native Development Environment without Android Studio

## Preface

Some of Mobile Developer (I don't know about iOS since they have particular hardware and software bundled for development) especially Android often had a tantrum about their machine being unnecessarily slow with the presence of Android Studio, well admitted I am too the one of them. With the rant comes the idea to make the life easier without that slow IDE, at the first sight, its hard to be possible but if you looking closely to the documentation, its not that hard. In this article, I am going to make an environment that can generate Android Apps with only the essential tools of Android Development.

## So, we are going to install something right?

Yes, the setting up activities are basically the installation matters for required tools and some adjustment for the tools installed before in strive for proper functionality of the tools. So we first define the tools required for the development environment setups. According to the React Native Docs, this list are required for the setups and to be noted that we will use the React Native CLI Quickstart. According to the list, I will explain list members at a glance before we continue.

- Node
- Java Development Kit
- Android Development Environment
- Watchman
- React Native CLI

Node is the runtime environment of the JavaScript development, all of React Native development things runs on Node environment and the JavaScript version of Java Development Kit (JDK). JDK itself is not runtime environment, it is the compiler used to compile Java code into executable form, we don't need Runtime Environment (JRE) yet since the scope of this article are to develop, not run the Java exec. Android Development Environment (ADE) of course must be installed in case we want to develop Android Apps, ADE is bundled with Android Studio so if you install Android Studio, you are automatically installing ADE, but in this case, we will skip Android Studio for a while and focused to main component of the ADE, the Android SDK. Watchman is file changes watching tools, yeah you might say like Git but little bit modern from Facebook. React Native CLI take part of the development as the main controller of the runtime.

## How do we install it, anyway?

The 'how' thing may vary depends on your OS, but i will show you the steps for Fedora. The installation pipeline must be defined in the beginning of this section in fact that the writing of the list in front of the explanation is far more understandable than not.

1. Install JDK and NodeJS.
2. Download sdkmanager.
3. Add path and aliases on '.bashrc'.
4. Install SDK component.
5. Create Android project directory.
6. Install required packages.

Before we continue, the sequence above are not an absolute sequence, you can do step 1, 2 and three concurrently depend on your hardware and internet spec, but step 4 until 6 are meant to be done sequentially. Hence the installation sequence written, let me advance to the 'how'.

You can start with installing JDK first, then Node or else sequentially done then in one installation command.

{% highlight bash %}


sudo dnf install java-latest-openjdk-devel.x86_64 nodejs


{% endhighlight %}

To be noted that nodejs version in the repo is stable version, you can get current version by execute these command first.

{% highlight bash %}


sudo dnf install -y gcc-c++ make
curl -sL https://rpm.nodesource.com/setup_16.x | sudo -E bash -


{% endhighlight %}

Another way to install your Node is if you have any version of Python 3 (version 3 recommended) and virtualenv module installed on your Python, you can create a virtualenv and then create Node virtualenv by executing these commands.

{% highlight bash %}

# activate your virtualenv
source /path/to/virtualenv/bin/activate
# you can install nodeenv by execute
python -m pip install nodeenv
# create your nodeenv by
nodeenv <nodeenv-foldername>
## add option if you wish to install the specified version
nodeenv <nodeenv-foldername> --node=NODE_VER
### or
nodeenv <nodeenv-foldername> -n NODE_VER
# deactivate your virtualenv
deactivate
# and activate your nodeenv
source /path/to/nodeenv/bin/activate

{% endhighlight %}

While you can create node virtual environment, you can choose which version of node you want to install by adding '-n NODE_VER' or '--node=NODE_VER' option when you create your nodeenv.

While it takes some times, you can light up your I/O with downloading Android SDK by browsing to the Android Studio download site, go to 'Command line tools only' and download one based on your OS, choose Linux for this occasion, and then let them to be completed or you can add aliases on your '.bashrc' if you use bash shell (I am using bash shell in this article).

{% highlight bash %}
# add onto very bottom line of .bashrc
export ANDROID_HOME=$HOME/Android/Sdk
export ANDROID_SDK_ROOT=$HOME/Android/Sdk
export PATH=$PATH:$ANDROID_HOME/cmdline-tools/latest
export PATH=$PATH:$ANDROID_HOME/platform-tools

alias sdkmanager=$ANDROID_HOME/cmdline-tools/latest/bin/sdkmanager
alias adb=$ANDROID_HOME/platform-tools/adb
{% endhighlight %}

After Android SDK successfully downloaded, you can take the folder to your home directory to get aligned with your '.bashrc' or adjust your '.bashrc' based on your current Android SDK folder location. Downloaded .zip can be stored in '$HOME/Android/Sdk' and make new directory on 'cmdline-tools' (folder you just unzipped) name it 'latest' and move the rest of 'cmdline-tools' occupants to 'latest' folder, said instructions ran in case of you want to aligned your SDK tools with your '.bashrc'. If the SDK were clearly installed, you can execute this command to install its component.

{% highlight bash %}
# installing the platform tools required for development (ADB...etc)
sdkmanager "platform-tools" "platforms;android-28"
# installing the build tools to build React Native to Android App
sdkmanager "build-tools;31.0.0-rc4"
{% endhighlight %}

SDK now ready to be used, so we first ensure the node are installed by checking 'node' command
{% highlight bash %}
node --v
{% endhighlight %}

if the version appears, you can advance to next sequence else you must reinstall you NodeJS using method said above. You can create the React Native project by executing
{% highlight bash %}
npx react-native init yourprojectName
{% endhighlight %}

Then you have to wait until the process finished, after the process completion, you can install node packages required by your project, since this project are starting point of the React Native Apps, the required packages may vary depend on what app do you wish to develop.
{% highlight bash %}
npm install
{% endhighlight %}

If you need to know the required packages your project had to satisfy, you can open your project's 'package.json'. In this point, the sequence was all done then the environment setup is finished, so you can develop your own project with them tools.

## You install all of the required tools? I don't see watchman in action, though.

Watchman is automatically installed on the creation of your project's folder (step 5 of the installation sequence) so you don't bother downloading it and place it to your folder over again.

## Bonus: Run your Android App in your device

Decided to make some additional references of how to run your Android App in your physical Android Device, since it was pretty simple to do. First, ensure the previous required Node packages are provided, if not, you can try installing them again by.
{% highlight bash %}
npm install
{% endhighlight %}

If all packages are provided, then you can run the engine called 'Metro' that act as JavaScript bundler by execute this command.
{% highlight bash %}
npx react-native start
{% endhighlight %}

Open another terminal, run this command
{% highlight bash %}
npx react-native run-android
{% endhighlight %}

Before the command mentioned above, you have to ensure your device is connected properly to the ADB by identifying your device, the id can be obtained by executing
{% highlight bash %}
lsusb
# the output must be list of devices connected through BUS interface
{% endhighlight %}

Identify your device by executing it when device unplugged and when device plugged to your USB port and see the 'lsusb' output differences, take as an example this device.
{% highlight bash %}
# difference between two outputs of 'lsusb'
Bus 001 Device 003: ID 22b8:2e76 Motorola PCS
{% endhighlight %}

Hence the example, take the ID as '22b8', then you must add udev rule by executing above command, remember to replace the ID with your own.
{% highlight bash %}
echo 'SUBSYSTEM=="usb", ATTR{idVendor}=="22b8", MODE="0666", GROUP="plugdev"' | sudo tee /etc/udev/rules.d/51-android-usb.rules
{% endhighlight %}

And then you can check the Android Device connected to your computer, to be remembered that your Android device must be in USB debugging mode to be able to do this task so enable it before you can find it on adb by
{% highlight bash %}
adb devices
{% endhighlight %}

If available, then you can run this command once again to run debugger mode on your device
{% highlight bash %}
npx react-native run-android
{% endhighlight %}

Wait until the App shows up on your Android screen and it is the debugger mode of your app. The End.


## Article Source
- [https://reactnative.dev/docs/environment-setup][https://reactnative.dev/docs/environment-setup]
- [https://developer.android.com/studio][https://developer.android.com/studio]
- [https://docs.fedoraproject.org/en-US/quick-docs/installing-java/][https://docs.fedoraproject.org/en-US/quick-docs/installing-java/]
- [https://pypi.org/project/nodeenv/][https://pypi.org/project/nodeenv/]

[https://reactnative.dev/docs/environment-setup]: https://reactnative.dev/docs/environment-setup
[https://developer.android.com/studio]: https://developer.android.com/studio
[https://docs.fedoraproject.org/en-US/quick-docs/installing-java/]: https://docs.fedoraproject.org/en-US/quick-docs/installing-java/
[https://pypi.org/project/nodeenv/]: https://pypi.org/project/nodeenv/
