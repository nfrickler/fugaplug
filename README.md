fugaplug
========

This is a try to develop a browser plugin enabling p2p Webcamchat.

<b>Plugin is not really working yet!</b>

Currently displays the own webcam (on Ubuntu using Firefox, Opera or Chromium)

Getting the source
==================

To get the complete source of this project including all embedded projects like
firebreath, use the following commands:

    git clone https://github.com/nfrickler/fugaplug.git
    cd fugaplug
    git submodule update --init --recursive


Installing the plugin
=====================

Install the plugin by switching to the fugaplug folder and running the following
commands:

    ./firebreath/prepmake.sh src build
    cd build/projects/fugaplug/
    make
    cp ../../bin/fugaplug/npfugaplug.so ~/.mozilla/plugins/

Open the file
    fugaplug/build/projects/fugaplug/gen/FBControl.htm
in your browser (e.g. firefox, chromium) to test the plugin.

For Opera you have to copy the so-File to:

    cp ../../bin/fugaplug/npfugaplug.so /usr/lib/opera/plugins/


Debugging
=========

On Linux you can easily debug plugins using one of the two commands below.

    firefox -d gdb
    chromium-browser --plugin-launcher='xterm -e gdb --args'
