//-----------------------------------------------------------------------------
/*
  The contents of this file are subject to the Initial Developer's Public
  License Version 1.0 (the "License"); you may not use this file except in
  compliance with the License. You may obtain a copy of the License here:
  http://www.flamerobin.org/license.html.

  Software distributed under the License is distributed on an "AS IS"
  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
  License for the specific language governing rights and limitations under
  the License.

  The Original Code is FlameRobin (TM).

  The Initial Developer of the Original Code is Nando Dessena.

  Portions created by the original developer
  are Copyright (C) 2005 Nando Dessena.

  All Rights Reserved.

  $Id$

  Contributor(s):
*/
//-----------------------------------------------------------------------------
#ifndef FR_FRERROR_H
#define FR_FRERROR_H

// Base class for all FlameRobin-specific exceptions.

#include <wx/wx.h>

#include <exception>
//-----------------------------------------------------------------------------
#define BEGIN_EVENT_HANDLER try {

#define END_EVENT_HANDLER } catch (std::exception& e) { handleException(e); }
//-----------------------------------------------------------------------------
void handleException(std::exception& e);
//-----------------------------------------------------------------------------
class FRError: public std::exception
{
private:
    char *messageM;

public:
    FRError(const wxString& message);
    FRError(const FRError& source);
    virtual const char* what() const throw();

    ~FRError() throw();
};
//-----------------------------------------------------------------------------
#endif //FR_FRERROR_H
