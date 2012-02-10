#ifndef OMG_DDS_SUB_DETAIL_DATA_READER_HPP_
#define OMG_DDS_SUB_DETAIL_DATA_READER_HPP_

/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Corp.
 * Copyright 2010, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//#include <dds/sub/LoanedSamples.hpp>

namespace dds { namespace sub { namespace functors { namespace detail {
class ContentFilterManipulatorFunctor {
public:
	ContentFilterManipulatorFunctor(const dds::core::Query& q)
	: query_(q) { }

	template <typename S>
	void operator()(S& s) {
		s.filter_content(query_);
	}
private:
	dds::core::Query query_;
};

class StateFilterManipulatorFunctor {
public:
	StateFilterManipulatorFunctor(const dds::sub::status::DataState& s)
	: state_(s) { }

	template <typename S>
	void operator()(S& s) {
		s.filter_state (state_);
	}
private:
	dds::sub::status::DataState state_;
};

class InstanceManipulatorFunctor {
public:
	InstanceManipulatorFunctor(const dds::core::InstanceHandle& h)
	: handle_(h) { }

	template <typename S>
	void operator()(S& s) {
		s.instance(handle_);
	}
private:
	dds::core::InstanceHandle handle_;
};

class NextInstanceManipulatorFunctor {
public:
	NextInstanceManipulatorFunctor(const dds::core::InstanceHandle& h)
	: handle_(h) { }

	template <typename S>
	void operator()(S& s) {
		s.next_instance(handle_);
	}
private:
	dds::core::InstanceHandle handle_;

};

} } } }


namespace dds { namespace sub { namespace detail {

template <typename T>
class DataReader {
public:
	class Selector {
	public:
		Selector(DataReader<T>* dr)
		: dr_(dr),
		  status_(dr_->default_status_filter()),
		  next_instance_(false),
		  handle_(dds::core::null),
		  has_query_(false),
		  query_("")
		{ }


		Selector& instance(const dds::core::InstanceHandle& h) {
			next_instance_ = false;
			handle_ = h;
			return *this;
		}

		Selector& next_instance(const dds::core::InstanceHandle& h) {
			next_instance_ = true;
			handle_ = h;
			return *this;
		}

		Selector& filter_state(const dds::sub::status::DataState& s) {
			status_ = s;
			return *this;
		}

		Selector& filter_content(const dds::core::Query& query) {
			query_ = query;
			return *this;
		}

		dds::sub::LoanedSamples<T>
		read()
		{
			return dr_->read(*this);
		}

		dds::sub::LoanedSamples<T>
		take()
		{
			return dr_->take(*this);
		}

		// --- Forward Iterators: --- //
		template <typename SamplesFWIterator, typename InfoFWIterator>
		void
		read(SamplesFWIterator sfit,
				InfoFWIterator ifit,
				size_t max_samples)
		{
			dr_->read(sfit, ifit, max_samples, *this);
		}

		template <typename SamplesFWIterator, typename InfoFWIterator>
		void
		take(SamplesFWIterator sfit,
				InfoFWIterator ifit,
				size_t max_samples)
		{
			dr_->take(sfit, ifit, max_samples, *this);
		}


		// --- Back-Inserting Iterators: --- //
		template <typename SamplesBIIterator, typename InfoBIIterator>
		void
		read(SamplesBIIterator sbit,
				InfoBIIterator ibit)
		{
			dr_->read(sbit, ibit, *this);
		}


		template <typename SamplesBIIterator, typename InfoBIIterator>
		void
		take(SamplesBIIterator sbit,
				InfoBIIterator ibit)
		{
			dr_->take(sbit, ibit, *this);
		}
	private:
		DataReader<T>*					dr_;
		dds::sub::status::DataState 	status_;
		bool							next_instance_;
		dds::core::InstanceHandle		handle_;
		bool							has_query_;
		dds::core::Query				query_;
	};

	class ManipulatorSelector : public Selector {
	public:
		ManipulatorSelector(DataReader<T>* dr): Selector(dr), read_mode_(true) { }
		bool read_mode() { return read_mode_; }

		void read_mode(bool b) { read_mode_ = b; }

		ManipulatorSelector&
		operator >>(dds::sub::LoanedSamples<T>& samples) {
			if (read_mode_) samples = this->Selector::read();
			else samples = this->Selector::take();
			return *this;
		}
	private:
		bool read_mode_;
	};
	public:
	DataReader(const dds::sub::Subscriber& pub,
			const ::dds::topic::Topic<T>& topic) { }

	DataReader(const dds::sub::Subscriber& pub,
			const ::dds::topic::Topic<T>& topic,
			const dds::sub::qos::DataReaderQos& qos,
			dds::sub::DataReaderListener<T>* listener,
			const dds::core::status::StatusMask& mask) { }

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

	DataReader(const dds::sub::Subscriber& pub,
			const ::dds::topic::ContentFilteredTopic<T>& topic) { }

	DataReader(const dds::sub::Subscriber& pub,
			const ::dds::topic::ContentFilteredTopic<T>& topic,
			const dds::sub::qos::DataReaderQos& qos,
			dds::sub::DataReaderListener<T>* listener,
			const dds::core::status::StatusMask& mask) { }
#endif /* OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT */

#ifdef OMG_DDS_MULTI_TOPIC_SUPPORT
	DataReader(const dds::sub::Subscriber& pub,
			const ::dds::topic::MultiTopic<T>& topic) { }

	DataReader(const dds::sub::Subscriber& pub,
			const ::dds::topic::MultiTopic<T>& topic,
			const dds::sub::qos::DataReaderQos& qos,
			dds::sub::DataReaderListener<T>* listener,
			const dds::core::status::StatusMask& mask) { }
#endif /* OMG_DDS_MULTI_TOPIC_SUPPORT */
	public:
	/**
	 * Returns a <code>StatusCondition</code> instance associated with
	 * this <code>Entity</code>.
	 */
	template <typename SELF>
	::dds::core::cond::StatusCondition<SELF>
	status_condition(const SELF& self) const {
		return ::dds::core::cond::StatusCondition<SELF>(
				new dds::core::cond::detail::StatusCondition<SELF>(self));
	}

	public:
	const dds::sub::status::DataState& default_status_filter() {
		return status_filter_;
	}
	DataReader& default_status_filter(const dds::sub::status::DataState& status) {
		status_filter_ = status;
		return *this;
	}

	public:
	dds::sub::LoanedSamples<T> take() {
		std::cout << "DataReader::take : LoanedSamples<T>" << std::endl;
		return dds::sub::LoanedSamples<T>();
	}

	dds::sub::LoanedSamples<T> read() {
		std::cout << "DataReader::read : LoanedSamples<T>" << std::endl;
		return dds::sub::LoanedSamples<T>();
	}

	// --- Forward Iterators: --- //
	template <typename SamplesFWIterator, typename InfoFWIterator>
	void
	read(SamplesFWIterator sfit,
			InfoFWIterator ifit,
			size_t max_samples)
	{
		std::cout << "DataReader::read(FWDIterator)" << std::endl;
	}

	template <typename SamplesFWIterator, typename InfoFWIterator>
	void
	take(SamplesFWIterator sfit,
			InfoFWIterator ifit,
			size_t max_samples)
	{
		std::cout << "DataReader::take(FWDIterator)" << std::endl;
	}


	// --- Back-Inserting Iterators: --- //
	template <typename SamplesBIIterator, typename InfoBIIterator>
	void
	read(SamplesBIIterator sbit,
			InfoBIIterator ibit)
	{
		std::cout << "DataReader::read(FWDIterator)" << std::endl;	}


	template <typename SamplesBIIterator, typename InfoBIIterator>
	void
	take(SamplesBIIterator sbit,
			InfoBIIterator ibit)
	{
		std::cout << "DataReader::take(FWDIterator)" << std::endl;
	}

	//========================================================================
	//== Status API
	const dds::core::status::LivelinessChangedStatus&
	liveliness_changed_status() const {
		return liveliness_status_;
	}

	const dds::core::status::SampleRejectedStatus&
	sample_rejected_status() const {
		return sample_rejected_status_;
	}

	const dds::core::status::SampleLostStatus&
	sample_lost_status() const {
		return sample_lost_status_;
	}

	const dds::core::status::RequestedDeadlineMissedStatus&
	requested_deadline_missed_status() {
		return deadline_missed_status_;

	}

	const dds::core::status::RequestedIncompatibleQosStatus&
	requested_incompatible_qos_status() const {
		return incompatible_qos_status_;
	}

	const dds::core::status::SubscriptionMatchedStatus&
	subscription_matched_status() const {
		return subscription_matched_status_;
	}

	private:
	// ==============================================================
	// == Selector Read/Take API
	dds::sub::LoanedSamples<T> take(const Selector& cmd) {
		std::cout << "DataReader::Selector::read" << std::endl;
		return dds::sub::LoanedSamples<T>();
	}


	dds::sub::LoanedSamples<T> read(const Selector& cmd) {
		std::cout << "DataReader::Selector::read" << std::endl;
		return dds::sub::LoanedSamples<T>();
	}

	// --- Forward Iterators: --- //
	template <typename SamplesFWIterator, typename InfoFWIterator>
	void
	read(SamplesFWIterator sfit,
			InfoFWIterator ifit,
			size_t max_samples, const Selector& cmd)
	{
		std::cout << "DataReader::Selector::read" << std::endl;
	}

	template <typename SamplesFWIterator, typename InfoFWIterator>
	void
	take(SamplesFWIterator sfit,
			InfoFWIterator ifit,
			size_t max_samples, const Selector& cmd)
	{
		std::cout << "DataReader::Selector::read" << std::endl;
	}


	// --- Back-Inserting Iterators: --- //
	template <typename SamplesBIIterator, typename InfoBIIterator>
	void
	read(SamplesBIIterator sbit,
			InfoBIIterator ibit, const Selector& cmd)
	{
		std::cout << "DataReader::Selector::read" << std::endl;
	}


	template <typename SamplesBIIterator, typename InfoBIIterator>
	void
	take(SamplesBIIterator sbit,
			InfoBIIterator ibit, const Selector& cmd)
	{
		std::cout << "DataReader::Selector::read" << std::endl;
	}

	private:
	dds::sub::status::DataState 						status_filter_;
	dds::core::status::LivelinessChangedStatus 			liveliness_status_;
	dds::core::status::SampleRejectedStatus    			sample_rejected_status_;
	dds::core::status::SampleLostStatus					sample_lost_status_;
	dds::core::status::RequestedDeadlineMissedStatus 	deadline_missed_status_;
	dds::core::status::RequestedIncompatibleQosStatus	incompatible_qos_status_;
	dds::core::status::SubscriptionMatchedStatus		subscription_matched_status_;
};

} } }

#endif /* OMG_TDDS_SUB_DETAIL_DATA_READER_HPP_ */
