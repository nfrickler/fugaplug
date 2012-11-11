/**********************************************************\

  Auto-generated fugaplug.cpp

  This file contains the auto-generated main plugin object
  implementation for the fugaplug project

\**********************************************************/

#include "fugaplugAPI.h"
#include <gst/gst.h>
#include <gtk/gtk.h>

#include <X11/Xlib.h>
#include "X11/PluginWindowX11.h"

#include "fugaplug.h"
#include "FugaStreamer.h"
#include "FugaVideo.h"

///////////////////////////////////////////////////////////////////////////////
/// @fn fugaplug::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginInitialize()
///
/// @see FB::FactoryBase::globalPluginInitialize
///////////////////////////////////////////////////////////////////////////////
void fugaplug::StaticInitialize()
{
    // Place one-time initialization stuff here; As of FireBreath 1.4 this should only
    // be called once per process

    if (!g_thread_supported ()) g_thread_init (NULL);
    gst_init (NULL, NULL);
}

///////////////////////////////////////////////////////////////////////////////
/// @fn fugaplug::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginDeinitialize()
///
/// @see FB::FactoryBase::globalPluginDeinitialize
///////////////////////////////////////////////////////////////////////////////
void fugaplug::StaticDeinitialize()
{
    // Place one-time deinitialization stuff here. As of FireBreath 1.4 this should
    // always be called just before the plugin library is unloaded
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  fugaplug constructor.  Note that your API is not available
///         at this point, nor the window.  For best results wait to use
///         the JSAPI object until the onPluginReady method is called
///////////////////////////////////////////////////////////////////////////////
fugaplug::fugaplug()
{
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  fugaplug destructor.
///////////////////////////////////////////////////////////////////////////////
fugaplug::~fugaplug()
{
    // This is optional, but if you reset m_api (the shared_ptr to your JSAPI
    // root object) and tell the host to free the retained JSAPI objects then
    // unless you are holding another shared_ptr reference to your JSAPI object
    // they will be released here.
    releaseRootJSAPI();
    m_host->freeRetainedObjects();
}

void fugaplug::onPluginReady()
{
    // When this is called, the BrowserHost is attached, the JSAPI object is
    // created, and we are ready to interact with the page and such.  The
    // PluginWindow may or may not have already fire the AttachedEvent at
    // this point.
}

void fugaplug::shutdown()
{
    // This will be called when it is time for the plugin to shut down;
    // any threads or anything else that may hold a shared_ptr to this
    // object should be released here so that this object can be safely
    // destroyed. This is the last point that shared_from_this and weak_ptr
    // references to this object will be valid
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  Creates an instance of the JSAPI object that provides your main
///         Javascript interface.
///
/// Note that m_host is your BrowserHost and shared_ptr returns a
/// FB::PluginCorePtr, which can be used to provide a
/// boost::weak_ptr<fugaplug> for your JSAPI class.
///
/// Be very careful where you hold a shared_ptr to your plugin class from,
/// as it could prevent your plugin class from getting destroyed properly.
///////////////////////////////////////////////////////////////////////////////
FB::JSAPIPtr fugaplug::createJSAPI()
{
    // m_host is the BrowserHost
    return boost::make_shared<fugaplugAPI>(FB::ptr_cast<fugaplug>(shared_from_this()), m_host);
}

bool fugaplug::onMouseDown(FB::MouseDownEvent *evt, FB::PluginWindow *)
{
    //printf("Mouse down at: %d, %d\n", evt->m_x, evt->m_y);
    return false;
}

bool fugaplug::onMouseUp(FB::MouseUpEvent *evt, FB::PluginWindow *)
{
    //printf("Mouse up at: %d, %d\n", evt->m_x, evt->m_y);
    return false;
}

bool fugaplug::onMouseMove(FB::MouseMoveEvent *evt, FB::PluginWindow *)
{
    //printf("Mouse move at: %d, %d\n", evt->m_x, evt->m_y);
    return false;
}
bool fugaplug::onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow * win)
{
    // The window is attached; act appropriately

    FB::PluginWindowX11* X11Window = dynamic_cast<FB::PluginWindowX11*>(win);
    GdkNativeWindow XID = X11Window->getWindow();
    int x_window_id = (int) XID;

    std::string ip = "127.0.0.1";
    int port = 5000;
    std::string path = "";
    FugaStreamer* streamer = new FugaStreamer(ip, port, path);
    streamer->start();

    FugaVideo* video = new FugaVideo(ip, port);
    video->start(x_window_id);

    return false;
}

bool fugaplug::onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *)
{
    // The window is about to be detached; act appropriately
    return false;
}
