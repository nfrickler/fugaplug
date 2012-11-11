#ifndef __FUGASTREAMER_H__
#define __FUGASTREAMER_H__

#include <gst/gst.h>
#include <string>

class FugaStreamer {

    public:
	FugaStreamer(std::string in_ip, int in_firstport, std::string in_path);
	~FugaStreamer();

	GstElement* getAudiohandler();
	GstElement* getVideohandler();

	void start();
	void stop();

    protected:
	std::string m_ip;
	int m_firstport;
	std::string m_path;

	GstElement* m_pipeline;
	GstElement* m_videohandler;
	GstElement* m_audiohandler;

};

#endif // __FUGASTREAMER_H__
