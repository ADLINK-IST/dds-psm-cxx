#include <iostream>
#include <dds/pub/test/testPub.hpp>
#include <dds/pub/DataWriter.hpp>
#include <dds/pub/DataWriterListener.hpp>

using namespace dds::pub;
using namespace dds::domain;
using namespace dds::core;
using namespace dds::topic;


class Point {
public:
    uint32_t x;
    uint32_t y;
};

std::ostream& operator <<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

namespace dds { namespace topic { 
    template<> struct is_topic_type<Point> { 
        enum { value = 1 };
    };
    
    template<> struct topic_type_name<Point> {
        static std::string value() { return "Point"; }
    };
} }


class PointDataWriterListener : public NoOpDataWriterListener<Point>  {
public:
    virtual ~PointDataWriterListener() { }
};

int
dds::pub::test::testPub() {
    
    DomainParticipant dp(DomainId::default_domain());
    Topic<Point> topic(dp, "PointTopic");
    Publisher pub(dp);
    qos::PublisherQos pubQos;
    pubQos << policy::Partition("Partition");
    
    Publisher pub2(dp, pubQos, 0, status::StatusMask::all());
    PointDataWriterListener* listener = new PointDataWriterListener();

    DataWriter<Point> dw(pub,
                          topic, 
                          qos::DataWriterQos(), 
                          listener, 
                          status::StatusMask::all());
    

    Point p1 = {10, 20};
    std::cout << ">> Writing: " << p1 << std::endl;    
    dw << p1;
    dw.write(p1);

    return 0;
}

