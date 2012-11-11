#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for fugaplug
#
#\**********************************************************/

set(PLUGIN_NAME "fugaplug")
set(PLUGIN_PREFIX "FUG")
set(COMPANY_NAME "nfrickler")

# ActiveX constants:
set(FBTYPELIB_NAME fugaplugLib)
set(FBTYPELIB_DESC "fugaplug 1.0 Type Library")
set(IFBControl_DESC "fugaplug Control Interface")
set(FBControl_DESC "fugaplug Control Class")
set(IFBComJavascriptObject_DESC "fugaplug IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "fugaplug ComJavascriptObject Class")
set(IFBComEventSource_DESC "fugaplug IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID 353bc73b-d0af-56c1-9440-5f229eb12504)
set(IFBControl_GUID a77a432b-dcce-5bf4-a3e5-f24b008a3dcc)
set(FBControl_GUID 835eafda-1638-5f43-ace3-5a1e4032dd28)
set(IFBComJavascriptObject_GUID e3a625e0-ce49-5a00-9c12-e6413173a49f)
set(FBComJavascriptObject_GUID bd57431d-b6ab-52d2-b74f-7618a0e1e4f1)
set(IFBComEventSource_GUID 3915e4c8-e212-5ff2-980b-ee689d8677f5)

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "nfrickler.fugaplug")
set(MOZILLA_PLUGINID "nif7.de/fugaplug")

# strings
set(FBSTRING_CompanyName "nfrickler")
set(FBSTRING_FileDescription "peer2peer webcam streaming")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2012 nfrickler")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "fugaplug")
set(FBSTRING_FileExtents "")
set(FBSTRING_PluginName "fugaplug")
set(FBSTRING_MIMEType "application/x-fugaplug")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

#set (FB_GUI_DISABLED 0)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 1)
set(FBMAC_USE_COCOA 1)
set(FBMAC_USE_COREGRAPHICS 1)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
