//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------
#ifndef COMMBASICOBJECTS_COMMFILEREADREQUEST_ACE_H_
#define COMMBASICOBJECTS_COMMFILEREADREQUEST_ACE_H_

#include "CommBasicObjects/CommFileReadRequest.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommFileReadRequest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommBasicObjectsIDL::CommFileReadRequest &data);

// de-serialization operator for DataStructure CommFileReadRequest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommBasicObjectsIDL::CommFileReadRequest &data);

// serialization operator for CommunicationObject CommFileReadRequest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommBasicObjects::CommFileReadRequest &obj);

// de-serialization operator for CommunicationObject CommFileReadRequest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommBasicObjects::CommFileReadRequest &obj);

#endif /* COMMBASICOBJECTS_COMMFILEREADREQUEST_ACE_H_ */
