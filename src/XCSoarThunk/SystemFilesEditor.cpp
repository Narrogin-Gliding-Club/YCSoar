/*
Copyright_License {

  YCSoar Glide Computer.
  Copyright (C) 2013-2017 Peter F Bradshaw
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#include <QTreeView>
#include <QFileSelector>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QItemSelectionModel>
#include "SystemFilesEditor.hpp"

#include <iostream>

//------------------------------------------------------------------------------
SystemFilesEditor::SystemFilesEditor()
  {
  this->mapGroup         = new QGroupBox(tr("Map"));
  this->waypointGroup    = new QGroupBox(tr("Waypoint"));
  this->airspaceGroup    = new QGroupBox(tr("Airspace"));
  QFormLayout *mapLayout = new QFormLayout;
  mapLayout->addRow(new QLabel(tr("File name here")), new QPushButton("Change"));

  QPushButton *closeButton = new QPushButton(tr("Close"));
  connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
  QHBoxLayout *buttonsLayout = new QHBoxLayout;
  buttonsLayout->addStretch(1);
  buttonsLayout->addWidget(closeButton);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addLayout(mapLayout);
  mainLayout->addLayout(buttonsLayout);
  this->setLayout(mainLayout);
  this->setWindowTitle("System Files");
  this->setSizeGripEnabled(true);
  }

//------------------------------------------------------------------------------
SystemFilesEditor::~SystemFilesEditor()
  {
  }

