/*
 * YCSoar Glide Computer.
 * Copyright (C) 2013-2015 Peter F Bradshaw
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \addtogroup XCSoarThunk
 * @{
 */
#ifndef __LOCALPATHTHUNK_HPP
#define __LOCALPATHTHUNK_HPP

#include "LocalPath.hpp"
#include "Util/NonCopyable.hpp"
#include "windef.h"
#include "tchar.h"

class QString;

/**
 * This class wraps and makes a singleton of XCSoar's LocalPathThunk.
 */
class LocalPathThunk : public NonCopyable
  {
public:
  /**
   * Instantiate the singleton object of this type.
   * @return The singleton;
   */
  static LocalPathThunk& Instance()
    {
    static LocalPathThunk self;
    return self;
    }

  /**
   * Give the local base data path.
   * @return The device dependant data path for XCSoar's use.
   */
  QString primaryDataPath() const;

  /**
   * Give the cache data path.
   * @return The device dependant data path for XCSoar's use.
   */
  QString cacheDataPath() const;

private:
  LocalPathThunk();

  TCHAR buffer[MAX_PATH];
  static QString cache;
  };

#endif  // __LOCALPATH_HPP
/**
 * @}
 */
