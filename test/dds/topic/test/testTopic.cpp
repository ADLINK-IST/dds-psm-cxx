#include <dds/topic/test/testTopic.hpp>

#include <dds/domain/DomainParticipant.hpp>
#include <dds/topic/ContentFilteredTopic.hpp>
#include <dds/topic/MultiTopic.hpp>
#include <dds/topic/TopicTraits.hpp>
#include <dds/core/Query.hpp>
#include <dds/topic/AnyTopicDescription.hpp>
#include <dds/topic/AnyTopic.hpp>
#include <dds/topic/TopicListener.hpp>

using namespace dds::domain;
using namespace dds::topic;
using namespace dds::core;

class Point {
public:
    uint32_t x_;
    uint32_t y_;

};

namespace dds { namespace topic { 
    template<> struct is_topic_type<Point> { 
        enum { value = 1 };
    };
    
    template<> struct topic_type_name<Point> {
        static std::string value() { return "Point"; }
    };
} }

class SampleTopicListener : public dds::topic::NoOpTopicListener<Point> { };

int dds::topic::test::testTopic() {

    DomainParticipant dp(DomainId::default_domain());

    // = Create simple topic
    Topic<Point> topic(dp, "PointTopic");

    std::cout 
        << "Topic Name = " << topic.name() 
        << " Type Name = " << topic.type_name()
    << std::endl;
    
    qos::TopicQos tqos;
    tqos << policy::Reliability::Reliable() 
         << policy::Durability::Transient()
         << policy::History::KeepLast(5);
    
    // = Topic Listener
    SampleTopicListener listener;

    // = Create a topic with QoS, listener and status mask
    Topic<Point> topic2(dp, 
                        "PointTopic2",
                        tqos, 
                        &listener,
                        status::StatusMask::offered_incompatible_qos()); 


    // = Content Filtered Topic
    std::string filter = "x_ > %0";
    std::vector<std::string> params;
    params.push_back("100");
    dds::core::Query query(filter, params);
    ContentFilteredTopic<Point> cfTopic(dds::core::null);

    // = Multi Topic
    MultiTopic<Point> mTopic(dp, "MultiTopicPoint", query);

    // == AnyTopicDescription Test
    TopicDescription<Point> ptd = topic;
    AnyTopicDescription atd(ptd);
    TopicDescription<Point> rtd = atd.get<Point>();

    // = AnyTopic Test
    AnyTopic at = topic;
    Topic<Point> rt = at.get<Point>();
    return 0;
}

