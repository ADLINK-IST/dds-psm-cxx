#include <dds/sub/test/testSub.hpp>
#include <dds/core/cond/WaitSet.hpp>
#include <dds/domain/DomainParticipant.hpp>
#include <dds/topic/ContentFilteredTopic.hpp>
#include <dds/topic/MultiTopic.hpp>
#include <dds/sub/sub.hpp>
#include <iostream>

using namespace dds::domain;
using namespace dds::sub;
using namespace dds::topic;

class Point {
public:
	Point(int32_t id, int32_t x, int32_t y)
	: id_(id), x_(x), y_(y) { }

	static Point key(int32_t id) {
		return Point(id, 0, 0);
	}
public:
	uint32_t id() const { return id_; }
	void id(int32_t i) { id_ = i; }

	uint32_t x() const { return x_; }
	void x(int32_t i) { x_ = i; }

	uint32_t y() const { return y_; }
		void y(int32_t i) { y_ = i; }

private:
	uint32_t id_; //@Key
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


int
dds::sub::test::testSub() {
    DomainParticipant dp(DomainId::default_domain());
    Topic<Point> topic(dp, "PointTopic");
    std::vector<std::string> params;
    dds::core::Query query("x < 100", params);

    ContentFilteredTopic<Point> cfTopic("FilteredPoint", topic, query);
    MultiTopic<Point> mTopic(dp, "MPoint", query);

    Subscriber sub(dp);


    // -- Test Reader

    // -- Reader on Content Filtered Topic
    DataReader<Point> cfDr(sub, cfTopic);

    // -- Reader on Multi-Topic
    DataReader<Point> mtDr(sub, mTopic);

    // -- WaitSet
    DataReader<Point> reader(sub, topic);

    dds::core::cond::WaitSet ws;
    dds::sub::cond::ReadCondition<Point> rc(reader, dds::sub::status::DataState::new_data());
    // attach read condition
    ws.attach_condition(rc);
    ws.wait();
    ws.detach_condition(rc);

    std::vector<std::string> p;
    p.push_back("100");
    p.push_back("100");
    dds::core::Query q("x < %0 AND y < %1", p.begin(), p.end());

    reader
    	.selector()
    		.filter_state(status::DataState::new_data())
    		.filter_content(q)
       .read();

    LoanedSamples<Point> samples;
    reader >> read >> samples;

    reader >> filter_content(q) >> samples;
    reader >> take >> filter_state(status::DataState::new_data()) >> filter_content(q) >> samples;

  //  reader.read_w_condition(0, data, status, lenght, ss, vs, is, qc);

   // dds::sub::cond::QueryCondition qc(reader, dds::sub::status::DataStatus::new_data(), q);
    //ws.attach_condition(qc);

    return 0;
}
