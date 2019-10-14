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
#include "CommBasicObjects/CommJoystickCore.hh"

// serialization/deserialization operators
//#include "CommBasicObjects/CommJoystickACE.hh"

// include the hash.idl containing the hash constant
#include "hash.hh"
#include <assert.h>
#include <cstring>
#include <iostream>

// SmartUtils used in from_xml method
#include "smartKnuthMorrisPratt.hh"

#ifdef ENABLE_HASH
	#include <boost/functional/hash.hpp>
#endif

namespace CommBasicObjects 
{
	const char* CommJoystickCore::getCompiledHash()
	{
		return CommBasicObjectsIDL::REPO_HASH;
	}
	
	void CommJoystickCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
	}
	
	void CommJoystickCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommJoystickCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
	}
	
	#ifdef ENABLE_HASH
	size_t CommJoystickCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		boost::hash_combine(seed, data.xpos);
		boost::hash_combine(seed, data.ypos);
		boost::hash_combine(seed, data.x2pos);
		boost::hash_combine(seed, data.y2pos);
		boost::hash_combine(seed, data.buttons);
		
		return seed;
	}
	#endif
	
	// default constructor
	CommJoystickCore::CommJoystickCore()
	:	idl_CommJoystick()
	{  
		setXpos(0);
		setYpos(0);
		setX2pos(0);
		setY2pos(0);
		setButtons(0);
	}
	
	CommJoystickCore::CommJoystickCore(const DATATYPE &data)
	:	idl_CommJoystick(data)
	{  }

	CommJoystickCore::~CommJoystickCore()
	{  }
	
	void CommJoystickCore::to_ostream(std::ostream &os) const
	{
	  os << "CommJoystick(";
	  os << getXpos() << " ";
	  os << getYpos() << " ";
	  os << getX2pos() << " ";
	  os << getY2pos() << " ";
	  os << getButtons() << " ";
	  os << ") ";
	}
	
	// convert to xml stream
	void CommJoystickCore::to_xml(std::ostream &os, const std::string &indent) const {
		os << indent << "<xpos>" << getXpos() << "</xpos>";
		os << indent << "<ypos>" << getYpos() << "</ypos>";
		os << indent << "<x2pos>" << getX2pos() << "</x2pos>";
		os << indent << "<y2pos>" << getY2pos() << "</y2pos>";
		os << indent << "<buttons>" << getButtons() << "</buttons>";
	}
	
	// restore from xml stream
	void CommJoystickCore::from_xml(std::istream &is) {
		static const Smart::KnuthMorrisPratt kmp_xpos("<xpos>");
		static const Smart::KnuthMorrisPratt kmp_ypos("<ypos>");
		static const Smart::KnuthMorrisPratt kmp_x2pos("<x2pos>");
		static const Smart::KnuthMorrisPratt kmp_y2pos("<y2pos>");
		static const Smart::KnuthMorrisPratt kmp_buttons("<buttons>");
		
		if(kmp_xpos.search(is)) {
			short xposItem;
			is >> xposItem;
			setXpos(xposItem);
		}
		if(kmp_ypos.search(is)) {
			short yposItem;
			is >> yposItem;
			setYpos(yposItem);
		}
		if(kmp_x2pos.search(is)) {
			short x2posItem;
			is >> x2posItem;
			setX2pos(x2posItem);
		}
		if(kmp_y2pos.search(is)) {
			short y2posItem;
			is >> y2posItem;
			setY2pos(y2posItem);
		}
		if(kmp_buttons.search(is)) {
			unsigned short buttonsItem;
			is >> buttonsItem;
			setButtons(buttonsItem);
		}
	}
	
	/*
	void CommJoystickCore::get(ACE_Message_Block *&msg) const
	{
		// start with a default internal buffer size(will automatically grow if needed)
		ACE_OutputCDR cdr(ACE_DEFAULT_CDR_BUFSIZE);
		
		CommBasicObjectsIDL::HashList hashes;
		getAllHashValues(hashes);
		cdr << static_cast<ACE_CDR::Long>(hashes.size());
		for(CommBasicObjectsIDL::HashList::const_iterator it=hashes.begin(); it!=hashes.end(); it++)
		{
			cdr << ACE_CString(it->c_str());
		}
		
		// Here the actual serialization takes place using the OutputCDR serialization operator<<
		// (see CommJoystickACE.hh)
		cdr << idl_CommJoystick;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommJoystick);
		cdr << data_hash;
		// std::cout << "CommJoystickCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommJoystickCore::set(const ACE_Message_Block *msg)
	{
		ACE_InputCDR cdr(msg);
	
		CommBasicObjectsIDL::HashList hashes;
		ACE_CDR::Long hashes_size;
		cdr >> hashes_size;
		for(int i=0; i<hashes_size; ++i) 
		{
			ACE_CString hash;
			cdr >> hash;
			hashes.push_back(hash.c_str());
		}
		checkAllHashValues(hashes);
		
		// Here the actual de-serialization takes place using the InputCDR serialization operator>>
		// (see CommJoystickACE.hh)
		cdr >> idl_CommJoystick;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommJoystick);
		assert(data_hash == own_hash);
		// std::cout << "CommJoystickCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace CommBasicObjects */
