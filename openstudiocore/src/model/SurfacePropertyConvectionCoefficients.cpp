/***********************************************************************************************************************
 *  OpenStudio(R), Copyright (c) 2008-2016, Alliance for Sustainable Energy, LLC. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 *  following conditions are met:
 *
 *  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *  disclaimer.
 *
 *  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *  following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote
 *  products derived from this software without specific prior written permission from the respective party.
 *
 *  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative
 *  works may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without
 *  specific prior written permission from Alliance for Sustainable Energy, LLC.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER, THE UNITED STATES GOVERNMENT, OR ANY CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************************************************************/

#include "SurfacePropertyConvectionCoefficients.hpp"
#include "SurfacePropertyConvectionCoefficients_Impl.hpp"

#include "Schedule.hpp"
#include "Schedule_Impl.hpp"

#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_SurfaceProperty_ConvectionCoefficients_FieldEnums.hxx>

#include "../utilities/units/Unit.hpp"

#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace model {

namespace detail {

  SurfacePropertyConvectionCoefficients_Impl::SurfacePropertyConvectionCoefficients_Impl(const IdfObject& idfObject,
                                                                                                                       Model_Impl* model,
                                                                                                                       bool keepHandle)
    : ModelObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == SurfacePropertyConvectionCoefficients::iddObjectType());
  }

  SurfacePropertyConvectionCoefficients_Impl::SurfacePropertyConvectionCoefficients_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                                                       Model_Impl* model,
                                                                                                                       bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == SurfacePropertyConvectionCoefficients::iddObjectType());
  }

  SurfacePropertyConvectionCoefficients_Impl::SurfacePropertyConvectionCoefficients_Impl(const SurfacePropertyConvectionCoefficients_Impl& other,
                                                                                                                       Model_Impl* model,
                                                                                                                       bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& SurfacePropertyConvectionCoefficients_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType SurfacePropertyConvectionCoefficients_Impl::iddObjectType() const {
    return SurfacePropertyConvectionCoefficients::iddObjectType();
  }

  std::vector<ScheduleTypeKey> SurfacePropertyConvectionCoefficients_Impl::getScheduleTypeKeys(const Schedule& schedule) const
  {
    // TODO: Check schedule display names.
    std::vector<ScheduleTypeKey> result;
    UnsignedVector fieldIndices = getSourceIndices(schedule.handle());
    UnsignedVector::const_iterator b(fieldIndices.begin()), e(fieldIndices.end());
    if (std::find(b,e,OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1ScheduleName) != e)
    {
      result.push_back(ScheduleTypeKey("SurfacePropertyConvectionCoefficients","Convection Coefficient 1"));
    }
    if (std::find(b,e,OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2ScheduleName) != e)
    {
      result.push_back(ScheduleTypeKey("SurfacePropertyConvectionCoefficients","Convection Coefficient 2"));
    }
    return result;
  }

  boost::optional<std::string> SurfacePropertyConvectionCoefficients_Impl::surfaceType() const {
    return getString(OS_SurfaceProperty_ConvectionCoefficientsFields::SurfaceType,true);
  }

  boost::optional<std::string> SurfacePropertyConvectionCoefficients_Impl::convectionCoefficient1Location() const {
    return getString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1Location,true);
  }

  boost::optional<std::string> SurfacePropertyConvectionCoefficients_Impl::convectionCoefficient1Type() const {
    return getString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1Type,true);
  }

  boost::optional<double> SurfacePropertyConvectionCoefficients_Impl::convectionCoefficient1() const {
    return getDouble(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1,true);
  }

  boost::optional<Schedule> SurfacePropertyConvectionCoefficients_Impl::convectionCoefficient1Schedule() const {
    return getObject<ModelObject>().getModelObjectTarget<Schedule>(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1ScheduleName);
  }

  boost::optional<std::string> SurfacePropertyConvectionCoefficients_Impl::convectionCoefficient2Location() const {
    return getString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2Location,true);
  }

  boost::optional<std::string> SurfacePropertyConvectionCoefficients_Impl::convectionCoefficient2Type() const {
    return getString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2Type,true);
  }

  boost::optional<double> SurfacePropertyConvectionCoefficients_Impl::convectionCoefficient2() const {
    return getDouble(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2,true);
  }

  boost::optional<Schedule> SurfacePropertyConvectionCoefficients_Impl::convectionCoefficient2Schedule() const {
    return getObject<ModelObject>().getModelObjectTarget<Schedule>(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2ScheduleName);
  }

  bool SurfacePropertyConvectionCoefficients_Impl::setSurfaceType(const std::string& surfaceType) {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficientsFields::SurfaceType, surfaceType);
    return result;
  }

  void SurfacePropertyConvectionCoefficients_Impl::resetSurfaceType() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficientsFields::SurfaceType, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficients_Impl::setConvectionCoefficient1Location(const std::string& convectionCoefficient1Location) {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1Location, convectionCoefficient1Location);
    return result;
  }

  void SurfacePropertyConvectionCoefficients_Impl::resetConvectionCoefficient1Location() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1Location, "");
    OS_ASSERT(result);
  }
  

  bool SurfacePropertyConvectionCoefficients_Impl::setConvectionCoefficient1Type(const std::string& convectionCoefficient1Type) {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1Type, convectionCoefficient1Type);
    return result;
  }

  void SurfacePropertyConvectionCoefficients_Impl::resetConvectionCoefficient1Type() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1Type, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficients_Impl::setConvectionCoefficient1(double convectionCoefficient1) {
    return setDouble(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1, convectionCoefficient1);
  }

  void SurfacePropertyConvectionCoefficients_Impl::resetConvectionCoefficient1() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficients_Impl::setConvectionCoefficient1Schedule(Schedule& schedule) {
    bool result = setSchedule(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1ScheduleName,
                              "SurfacePropertyConvectionCoefficients",
                              "Convection Coefficient 1",
                              schedule);
    return result;
  }

  void SurfacePropertyConvectionCoefficients_Impl::resetConvectionCoefficient1Schedule() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1ScheduleName, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficients_Impl::setConvectionCoefficient2Location(const std::string& convectionCoefficient2Location) {
    return setString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2Location, convectionCoefficient2Location);
  }

  void SurfacePropertyConvectionCoefficients_Impl::resetConvectionCoefficient2Location() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2Location, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficients_Impl::setConvectionCoefficient2Type(const std::string& convectionCoefficient2Type) {
    return setString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2Type, convectionCoefficient2Type);
  }

  void SurfacePropertyConvectionCoefficients_Impl::resetConvectionCoefficient2Type() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2Type, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficients_Impl::setConvectionCoefficient2(double convectionCoefficient2) {
    return setDouble(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2, convectionCoefficient2);
  }

  void SurfacePropertyConvectionCoefficients_Impl::resetConvectionCoefficient2() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficients_Impl::setConvectionCoefficient2Schedule(Schedule& schedule) {
    bool result = setSchedule(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2ScheduleName,
                              "SurfacePropertyConvectionCoefficients",
                              "Convection Coefficient 2",
                              schedule);
    return result;
  }

  void SurfacePropertyConvectionCoefficients_Impl::resetConvectionCoefficient2Schedule() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2ScheduleName, "");
    OS_ASSERT(result);
  }

} // detail

SurfacePropertyConvectionCoefficients::SurfacePropertyConvectionCoefficients(const Model& model)
  : ModelObject(SurfacePropertyConvectionCoefficients::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>());
}

IddObjectType SurfacePropertyConvectionCoefficients::iddObjectType() {
  return IddObjectType(IddObjectType::OS_SurfaceProperty_ConvectionCoefficients);
}

std::vector<std::string> SurfacePropertyConvectionCoefficients::surfaceTypeValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_SurfaceProperty_ConvectionCoefficientsFields::SurfaceType);
}

std::vector<std::string> SurfacePropertyConvectionCoefficients::convectionCoefficient1LocationValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1Location);
}

std::vector<std::string> SurfacePropertyConvectionCoefficients::convectionCoefficient1TypeValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient1Type);
}

std::vector<std::string> SurfacePropertyConvectionCoefficients::convectionCoefficient2LocationValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2Location);
}

std::vector<std::string> SurfacePropertyConvectionCoefficients::convectionCoefficient2TypeValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_SurfaceProperty_ConvectionCoefficientsFields::ConvectionCoefficient2Type);
}

boost::optional<std::string> SurfacePropertyConvectionCoefficients::surfaceType() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->surfaceType();
}

boost::optional<std::string> SurfacePropertyConvectionCoefficients::convectionCoefficient1Location() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->convectionCoefficient1Location();
}

boost::optional<std::string> SurfacePropertyConvectionCoefficients::convectionCoefficient1Type() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->convectionCoefficient1Type();
}

boost::optional<double> SurfacePropertyConvectionCoefficients::convectionCoefficient1() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->convectionCoefficient1();
}

boost::optional<Schedule> SurfacePropertyConvectionCoefficients::convectionCoefficient1Schedule() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->convectionCoefficient1Schedule();
}

boost::optional<std::string> SurfacePropertyConvectionCoefficients::convectionCoefficient2Location() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->convectionCoefficient2Location();
}

boost::optional<std::string> SurfacePropertyConvectionCoefficients::convectionCoefficient2Type() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->convectionCoefficient2Type();
}

boost::optional<double> SurfacePropertyConvectionCoefficients::convectionCoefficient2() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->convectionCoefficient2();
}

boost::optional<Schedule> SurfacePropertyConvectionCoefficients::convectionCoefficient2Schedule() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->convectionCoefficient2Schedule();
}

bool SurfacePropertyConvectionCoefficients::setSurfaceType(const std::string& surfaceType) {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->setSurfaceType(surfaceType);
}

void SurfacePropertyConvectionCoefficients::resetSurfaceType() {
  getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->resetSurfaceType();
}

bool SurfacePropertyConvectionCoefficients::setConvectionCoefficient1Location(const std::string& convectionCoefficient1Location) {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->setConvectionCoefficient1Location(convectionCoefficient1Location);
}

void SurfacePropertyConvectionCoefficients::resetConvectionCoefficient1Location() {
  getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->resetConvectionCoefficient1Location();
}

bool SurfacePropertyConvectionCoefficients::setConvectionCoefficient1Type(const std::string& convectionCoefficient1Type) {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->setConvectionCoefficient1Type(convectionCoefficient1Type);
}

void SurfacePropertyConvectionCoefficients::resetConvectionCoefficient1Type() {
  getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->resetConvectionCoefficient1Type();
}

bool SurfacePropertyConvectionCoefficients::setConvectionCoefficient1(double convectionCoefficient1) {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->setConvectionCoefficient1(convectionCoefficient1);
}

void SurfacePropertyConvectionCoefficients::resetConvectionCoefficient1() {
  getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->resetConvectionCoefficient1();
}

bool SurfacePropertyConvectionCoefficients::setConvectionCoefficient1Schedule(Schedule& schedule) {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->setConvectionCoefficient1Schedule(schedule);
}

void SurfacePropertyConvectionCoefficients::resetConvectionCoefficient1Schedule() {
  getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->resetConvectionCoefficient1Schedule();
}

bool SurfacePropertyConvectionCoefficients::setConvectionCoefficient2Location(const std::string& convectionCoefficient2Location) {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->setConvectionCoefficient2Location(convectionCoefficient2Location);
}

void SurfacePropertyConvectionCoefficients::resetConvectionCoefficient2Location() {
  getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->resetConvectionCoefficient2Location();
}

bool SurfacePropertyConvectionCoefficients::setConvectionCoefficient2Type(const std::string& convectionCoefficient2Type) {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->setConvectionCoefficient2Type(convectionCoefficient2Type);
}

void SurfacePropertyConvectionCoefficients::resetConvectionCoefficient2Type() {
  getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->resetConvectionCoefficient2Type();
}

bool SurfacePropertyConvectionCoefficients::setConvectionCoefficient2(double convectionCoefficient2) {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->setConvectionCoefficient2(convectionCoefficient2);
}

void SurfacePropertyConvectionCoefficients::resetConvectionCoefficient2() {
  getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->resetConvectionCoefficient2();
}

bool SurfacePropertyConvectionCoefficients::setConvectionCoefficient2Schedule(Schedule& schedule) {
  return getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->setConvectionCoefficient2Schedule(schedule);
}

void SurfacePropertyConvectionCoefficients::resetConvectionCoefficient2Schedule() {
  getImpl<detail::SurfacePropertyConvectionCoefficients_Impl>()->resetConvectionCoefficient2Schedule();
}

/// @cond
SurfacePropertyConvectionCoefficients::SurfacePropertyConvectionCoefficients(std::shared_ptr<detail::SurfacePropertyConvectionCoefficients_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

