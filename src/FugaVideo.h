#ifndef __FugaVideo_H__
#define __FugaVideo_H__

#include <glib.h>
#include <gst/gst.h>
#include <string>

class FugaVideo {

    public:
	FugaVideo(std::string in_ip, int in_firstport);
//	void resizeEvent(QResizeEvent *e);
	~FugaVideo();
	void start(int winid);
	void stop();

    protected:
	void init();
	GstElement* m_pipeline;
	GstElement* m_xvimagesink;

	// connection
	std::string m_ip;
	int m_firstport;
};

#endif // __FugaVideo_H__
