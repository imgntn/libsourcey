///
//
// LibSourcey
// Copyright (c) 2005, Sourcey <http://sourcey.com>
//
// SPDX-License-Identifier:	LGPL-2.1+
//
/// @addtogroup av
/// @{


#include "scy/av/codec.h"
#include <assert.h>
#include <sstream>


using std::endl;


namespace scy {
namespace av {


//
// Base Codec
//


Codec::Codec()
    : name("Unknown")
    , sampleRate(0)
    , bitRate(0)
    , quality(0)
    , enabled(false)
{
}

Codec::Codec(const std::string& name, int sampleRate, int bitRate, bool enabled)
    : name(name)
    , sampleRate(sampleRate)
    , bitRate(bitRate)
    , quality(0)
    , enabled(enabled)
{
}


Codec::Codec(const std::string& name, const std::string& encoder,
             int sampleRate, int bitRate, bool enabled)
    : name(name)
    , encoder(encoder)
    , sampleRate(sampleRate)
    , bitRate(bitRate)
    , enabled(enabled)
{
}


// Codec::Codec(const Codec& r) = default;
//
//
// Codec::~Codec() = default;
//
//
// Codec& Codec::operator=(const Codec& r) {
//     name = r.name;
//     encoder = r.encoder;
//     sampleRate = r.sampleRate;
//     bitRate = r.bitRate;
//     enabled = r.enabled;
//     return *this;
// }
//
//
// Codec::Codec(const Codec& r) :
//     name(r.name),
//     encoder(r.encoder),
//     sampleRate(r.sampleRate),
//     bitRate(r.bitRate),
//     enabled(r.enabled)
// {
// }


Codec::~Codec()
{
}


std::string Codec::toString() const
{
    std::ostringstream os;
    os << "Codec[" << name << ":" << encoder << ":" << sampleRate << ":"
       << enabled << "]";
    return os.str();
}


void Codec::print(std::ostream& ost)
{
    ost << "Codec["
        //<< "\n\tID: " << id
        << "\n\tName: " << name << "\n\tEncoder: " << encoder
        << "\n\tSample Rate: " << sampleRate << "\n\tBit Rate: " << bitRate
        << "\n\tQuality: " << quality << "\n\tEnabled: " << enabled << "]";
}


//
// Audio Codec
//


AudioCodec::AudioCodec()
    : Codec("Unknown", 0, 0, false)
    , // DEFAULT_AUDIO_SAMPLE_RATE, DEFAULT_AUDIO_BIT_RATE
    // channels(DEFAULT_AUDIO_CHANNELS), sampleFmt(DEFAULT_AUDIO_SAMPLE_FMT)
    channels(0) //, sampleFmt(DEFAULT_AUDIO_SAMPLE_FMT)
{
    // assert(0);
}


AudioCodec::AudioCodec(const std::string& name, int channels, int sampleRate,
                       int bitRate, const std::string& sampleFmt)
    : Codec(name, encoder, sampleRate, bitRate, true)
    , channels(channels)
    , sampleFmt(sampleFmt)
{
}


AudioCodec::AudioCodec(const std::string& name, const std::string& encoder,
                       int channels, int sampleRate, int bitRate,
                       const std::string& sampleFmt)
    : Codec(name, encoder, sampleRate, bitRate, true)
    , channels(channels)
    , sampleFmt(sampleFmt)
{
}


// AudioCodec::AudioCodec(const AudioCodec& r) :
//     Codec(r.name, r.encoder, r.sampleRate, r.bitRate, r.enabled),
//     channels(r.channels), sampleFmt(r.sampleFmt)
// {
// }


// AudioCodec& AudioCodec::operator=(const AudioCodec& r) {
//     Codec::operator=(r);
//     channels = r.channels;
//     sampleFmt = r.sampleFmt;
//     return *this;
// }


AudioCodec::~AudioCodec()
{
}


std::string AudioCodec::toString() const
{
    std::ostringstream os;
    os << "AudioCodec[" << name << ":" << encoder << ":" << sampleRate << ":"
       << bitRate << ":" << channels << ":" << sampleFmt << ":" << enabled
       << "]";
    return os.str();
}


void AudioCodec::print(std::ostream& ost)
{
    ost << "AudioCodec["
        << "\n\tName: " << name << "\n\tEncoder: " << encoder
        << "\n\tSample Rate: " << sampleRate << "\n\tBit Rate: " << bitRate
        << "\n\tChannels: " << channels << "\n\tSample Fmt: " << sampleFmt
        << "\n\tQuality: " << quality << "\n\tEnabled: " << enabled << "]";
}


//
// Video Codec
//


VideoCodec::VideoCodec()
    : Codec("Unknown", 0, 0, false)
    , // DEFAULT_VIDEO_SAMPLE_RATE, DEFAULT_VIDEO_BIT_RATE
    width(0)
    , height(0)
    , fps(0) //, pixelFmt(DEFAULT_VIDEO_PIXEL_FMT)
{
}


VideoCodec::VideoCodec(const std::string& name, int width, int height,
                       double fps, int sampleRate, int bitRate,
                       const std::string& pixelFmt)
    : Codec(name, sampleRate, bitRate, true)
    , width(width)
    , height(height)
    , fps(fps)
    , pixelFmt(pixelFmt)
{
}


VideoCodec::VideoCodec(const std::string& name, const std::string& encoder,
                       int width, int height, double fps, int sampleRate,
                       int bitRate, const std::string& pixelFmt)
    : Codec(name, encoder, sampleRate, bitRate, true)
    , width(width)
    , height(height)
    , fps(fps)
    , pixelFmt(pixelFmt)
{
}


VideoCodec::VideoCodec(const VideoCodec& r)
    : Codec(r.name, r.encoder, r.sampleRate, r.bitRate, r.enabled)
    , width(r.width)
    , height(r.height)
    , fps(r.fps)
    , pixelFmt(r.pixelFmt)
{
}


VideoCodec::~VideoCodec()
{
}


std::string VideoCodec::toString() const
{
    std::ostringstream os;
    os << "VideoCodec[" << name << ":" << encoder << ":" << width << ":"
       << height << ":" << fps << ":" << pixelFmt << ":" << enabled << "]";
    return os.str();
}


void VideoCodec::print(std::ostream& ost)
{
    ost << "VideoCodec["
        << "\n\tName: " << name << "\n\tEncoder: " << encoder
        << "\n\tSample Rate: " << sampleRate << "\n\tBit Rate: " << bitRate
        << "\n\tWidth: " << width << "\n\tHeight: " << height
        << "\n\tFPS: " << fps << "\n\tPixel Format: " << pixelFmt
        << "\n\tQuality: " << quality << "\n\tEnabled: " << enabled << "]";
}


} // namespace av
} // namespace scy


/// @\}
