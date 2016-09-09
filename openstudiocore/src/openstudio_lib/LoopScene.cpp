/**********************************************************************
 *  Copyright (c) 2008-2016, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include "LoopScene.hpp"
#include "OSAppBase.hpp"
#include "GridItem.hpp"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QGraphicsItem>
#include <QMimeData>
#include <cmath>
#include "../model/Loop.hpp"
#include "../model/Model.hpp"
#include "../model/Model_Impl.hpp"
#include "../model/Splitter.hpp"
#include "../model/Mixer.hpp"
#include "../model/ModelObject.hpp"
#include "../model/HVACComponent.hpp"
#include "../model/HVACComponent_Impl.hpp"
#include "../model/StraightComponent.hpp"
#include "../model/StraightComponent_Impl.hpp"
#include "../model/AirLoopHVACOutdoorAirSystem.hpp"
#include "../model/AirLoopHVACOutdoorAirSystem_Impl.hpp"
#include "../model/ThermalZone.hpp"
#include "../model/ThermalZone_Impl.hpp"
#include "../model/Node.hpp"
#include "../model/Node_Impl.hpp"
#include <QTimer>

using namespace openstudio::model;

namespace openstudio {

LoopScene::LoopScene( model::Loop loop,
                      QObject * parent )
  : GridScene(parent),
    m_loop(loop),
    m_dirty(true)
{
  // loop.model().getImpl<model::detail::Model_Impl>().get()->addWorkspaceObjectPtr.connect<LoopScene, &LoopScene::addedWorkspaceObject>(this);
  connect(OSAppBase::instance(), &OSAppBase::workspaceObjectAddedPtr, this, &LoopScene::addedWorkspaceObject, Qt::QueuedConnection);

  loop.model().getImpl<model::detail::Model_Impl>().get()->removeWorkspaceObjectPtr.connect<LoopScene, &LoopScene::removedWorkspaceObject>(this);

  layout();
}

void LoopScene::initDefault()
{

}

void LoopScene::layout()
{
  if( m_dirty && !m_loop.handle().isNull() )
  {
    QList<QGraphicsItem *> itemList = items();
    for( QList<QGraphicsItem *>::iterator it = itemList.begin();
         it < itemList.end();
         ++it )
    {
      removeItem(*it);
      delete *it;
    }

    SystemItem * systemItem = new SystemItem(m_loop,this);

    systemItem->setPos(50,50);

    this->setSceneRect(0,0,(systemItem->getHGridLength() * 100) + 100, ((systemItem->getVGridLength()) * 100) + 100);

    update();

    m_dirty = false;
  }
}

DemandSideItem * LoopScene::createDemandSide()
{
  auto demandInletNodes = m_loop.demandInletNodes();
  auto demandOutletNode = m_loop.demandOutletNode();

  DemandSideItem * demandSideItem = new DemandSideItem( nullptr,
                                                        demandInletNodes,
                                                        demandOutletNode );

  return demandSideItem;
}

SupplySideItem * LoopScene::createSupplySide()
{
  auto supplyInletNode = m_loop.supplyInletNode();
  auto supplyOutletNodes = m_loop.supplyOutletNodes();

  SupplySideItem * supplySideItem = new SupplySideItem( nullptr,
                                                        supplyInletNode,
                                                        supplyOutletNodes);

  return supplySideItem;
}

model::Loop LoopScene::loop()
{
  return m_loop;
}

void LoopScene::addedWorkspaceObject(std::shared_ptr<openstudio::detail::WorkspaceObject_Impl> wPtr, const openstudio::IddObjectType& type, const openstudio::UUID& uuid )
{
  model::detail::HVACComponent_Impl* hvac_impl = dynamic_cast<model::detail::HVACComponent_Impl*>(wPtr.get());
  if(hvac_impl)
  {
    m_dirty = true;

    QTimer::singleShot(0,this,SLOT(layout()));
  }
}

void LoopScene::removedWorkspaceObject(std::shared_ptr<openstudio::detail::WorkspaceObject_Impl> wPtr, const openstudio::IddObjectType& type, const openstudio::UUID& uuid )
{
  m_dirty = true;

  QTimer::singleShot(0,this,SLOT(layout()));
}

} // openstudio

