// $Id$

#include "ContentFilteredTopic.h"
#include "Topic.h"
#include "StringSeq.h"

#include "ciao/Logger/Log_Macros.h"

namespace CIAO
{
  namespace DDS4CCM
  {
    namespace RTI
    {
      RTI_ContentFilteredTopic_i::RTI_ContentFilteredTopic_i (void)
        : impl_ (0)
      {
      }

      RTI_ContentFilteredTopic_i::~RTI_ContentFilteredTopic_i (void)
      {
      }

      char *
      RTI_ContentFilteredTopic_i::get_filter_expression (void)
      {
        CIAO_TRACE ("RTI_ContentFilteredTopic_i::get_filter_expression");
        return CORBA::string_dup (this->impl ()->get_filter_expression ());
      }

      ::DDS::ReturnCode_t
      RTI_ContentFilteredTopic_i::get_expression_parameters (
        ::DDS::StringSeq & expression_parameters)
      {
        CIAO_TRACE ("RTI_ContentFilteredTopic_i::get_expression_parameters");
        DDS_StringSeq parameters;
        ::DDS::ReturnCode_t retval = this->impl ()->get_expression_parameters (
                                                                    parameters);
        expression_parameters <<= parameters;
        return retval;
      }

      ::DDS::ReturnCode_t
      RTI_ContentFilteredTopic_i::set_expression_parameters (
        const ::DDS::StringSeq & expression_parameters)
      {
        CIAO_TRACE ("RTI_ContentFilteredTopic_i::set_expression_parameters");

        DDS_StringSeq parameters;
        parameters <<= expression_parameters;

        return this->impl ()->set_expression_parameters (parameters);
      }

      ::DDS::Topic_ptr
      RTI_ContentFilteredTopic_i::get_related_topic (void)
      {
        CIAO_TRACE ("RTI_ContentFilteredTopic_i::get_related_topic");
        DDSTopic *topic = this->impl ()->get_related_topic ();
        ::DDS::Topic_var retval = new RTI_Topic_i ();
        RTI_Topic_i *rti_topic = dynamic_cast < RTI_Topic_i *> (retval.in ());
        rti_topic->set_impl (topic);
        return retval._retn ();
      }

      char *
      RTI_ContentFilteredTopic_i::get_type_name (void)
      {
        return CORBA::string_dup (this->impl ()->get_type_name ());
      }

      char *
      RTI_ContentFilteredTopic_i::get_name (void)
      {
        return CORBA::string_dup (this->impl ()->get_name ());
      }

      ::DDS::DomainParticipant_ptr
      RTI_ContentFilteredTopic_i::get_participant (void)
      {
        DDSDomainParticipant* p = this->impl ()->get_participant ();
        ::DDS::DomainParticipant_var retval = new RTI_DomainParticipant_i ();
        RTI_DomainParticipant_i *rti_dp = dynamic_cast < RTI_DomainParticipant_i *> (retval.in ());
        rti_dp->set_impl (p);
        return retval._retn ();
      }

      DDSContentFilteredTopic *
      RTI_ContentFilteredTopic_i::get_impl (void)
      {
        return this->impl_;
      }

      void
      RTI_ContentFilteredTopic_i::set_impl (DDSContentFilteredTopic * dw)
      {
        this->impl_ = dw;
      }

      DDSContentFilteredTopic *
      RTI_ContentFilteredTopic_i::impl (void)
      {
        if (!this->impl_)
          {
            throw ::CORBA::BAD_INV_ORDER ();
          }
        return this->impl_;
      }

    }
  }
}