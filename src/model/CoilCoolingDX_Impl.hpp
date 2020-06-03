/***********************************************************************************************************************
*  OpenStudio(R), Copyright (c) 2008-2020, Alliance for Sustainable Energy, LLC, and other contributors. All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
*  following conditions are met:
*
*  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
*  disclaimer.
*
*  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
*  disclaimer in the documentation and/or other materials provided with the distribution.
*
*  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote products
*  derived from this software without specific prior written permission from the respective party.
*
*  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative works
*  may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without specific prior
*  written permission from Alliance for Sustainable Energy, LLC.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) AND ANY CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
*  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER(S), ANY CONTRIBUTORS, THE UNITED STATES GOVERNMENT, OR THE UNITED
*  STATES DEPARTMENT OF ENERGY, NOR ANY OF THEIR EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
*  USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
*  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
*  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***********************************************************************************************************************/

#ifndef MODEL_COILCOOLINGDX_IMPL_HPP
#define MODEL_COILCOOLINGDX_IMPL_HPP

#include <model/ModelAPI.hpp>
#include "StraightComponent_Impl.hpp"

namespace openstudio {
namespace model {

class Schedule;
class ThermalZone;
class CoilCoolingDXCurveFitPerformance;

namespace detail {

  /** CoilCoolingDX_Impl is a StraightComponent_Impl that is the implementation class for CoilCoolingDX.*/
  class MODEL_API CoilCoolingDX_Impl : public StraightComponent_Impl {
   public:
    /** @name Constructors and Destructors */
    //@{

    CoilCoolingDX_Impl(const IdfObject& idfObject,
                       Model_Impl* model,
                       bool keepHandle);

    CoilCoolingDX_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                       Model_Impl* model,
                       bool keepHandle);

    CoilCoolingDX_Impl(const CoilCoolingDX_Impl& other,
                       Model_Impl* model,
                       bool keepHandle);

    virtual ~CoilCoolingDX_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const override;

    virtual IddObjectType iddObjectType() const override;

    virtual std::vector<ScheduleTypeKey> getScheduleTypeKeys(const Schedule& schedule) const override;

    virtual unsigned inletPort() const override;

    virtual unsigned outletPort() const override;

    virtual ModelObject clone(Model model) const override;

    virtual std::vector<ModelObject> children() const override;

    virtual boost::optional<HVACComponent> containingHVACComponent() const override;

    virtual bool addToNode(Node & node) override;

    //@}
    /** @name Getters */
    //@{

    Schedule availabilitySchedule() const;

    boost::optional<ThermalZone> condenserZone() const;

    boost::optional<std::string> condenserInletNodeName() const;

    boost::optional<std::string> condenserOutletNodeName() const;

    CoilCoolingDXCurveFitPerformance performanceObject() const;

    // boost::optional<HVACComponent> condensateCollectionWaterStorageTank() const;

    // boost::optional<HVACComponent> evaporativeCondenserSupplyWaterStorageTank() const;

    //@}
    /** @name Setters */
    //@{

    bool setAvailabilitySchedule(Schedule& schedule);

    bool setCondenserZone(const ThermalZone& thermalZone);
    void resetCondenserZone();

    bool setCondenserInletNodeName(const std::string& condenserInletNodeName);
    void resetCondenserInletNodeName();

    bool setCondenserOutletNodeName(const std::string& condenserOutletNodeName);
    void resetCondenserOutletNodeName();

    bool setPerformanceObject(const CoilCoolingDXCurveFitPerformance& coilCoolingDXCurveFitPerformance);

    // bool setCondensateCollectionWaterStorageTank(const HVACComponent& condensateCollectionWaterStorageTank);
    // void resetCondensateCollectionWaterStorageTank();

    // bool setEvaporativeCondenserSupplyWaterStorageTank(const HVACComponent& evaporativeCondenserSupplyWaterStorageTank);
    // void resetEvaporativeCondenserSupplyWaterStorageTank();

    //@}
    /** @name Other */
    //@{


    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.CoilCoolingDX");

    boost::optional<Schedule> optionalAvailabilitySchedule() const;
    boost::optional<CoilCoolingDXCurveFitPerformance> optionalPerformanceObject() const;

    boost::optional<Connection> optionalAirInletNode() const;
    boost::optional<Connection> optionalAirOutletNode() const;
  };

} // detail

} // model
} // openstudio

#endif // MODEL_COILCOOLINGDX_IMPL_HPP

