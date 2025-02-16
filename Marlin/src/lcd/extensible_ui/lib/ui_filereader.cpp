/*********************
 * ui_filereader.cpp *
 *********************/

/****************************************************************************
 *   Written By Mark Pelletier  2017 - Aleph Objects, Inc.                  *
 *   Written By Marcio Teixeira 2018 - Aleph Objects, Inc.                  *
 *                                                                          *
 *   This program is free software: you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published by   *
 *   the Free Software Foundation, either version 3 of the License, or      *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   This program is distributed in the hope that it will be useful,        *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU General Public License for more details.                           *
 *                                                                          *
 *   To view a copy of the GNU General Public License, go to the following  *
 *   location: <http://www.gnu.org/licenses/>.                              *
 ****************************************************************************/

#include "ui.h"

#include "ui_filereader.h"

#if ENABLED(EXTENSIBLE_UI)

bool MediaFileReader::open(const char* filename) {
  card.init(SPI_SPEED, SDSS);
  volume.init(&card);
  root.openRoot(&volume);
  return file.open(&root, filename, O_READ);
}

int16_t MediaFileReader::read(void *buff, size_t bytes) {
  return file.read(buff, bytes);
}

void MediaFileReader::close() {
  file.close();
}

uint32_t MediaFileReader::size() {
  return file.fileSize();
}

void MediaFileReader::rewind() {
  file.rewind();
}

int16_t MediaFileReader::read(void *obj, void *buff, size_t bytes) {
  return reinterpret_cast<MediaFileReader*>(obj)->read(buff, bytes);
}

#endif // EXTENSIBLE_UI