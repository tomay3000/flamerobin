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

  The Initial Developer of the Original Code is Milan Babuskov.

  Portions created by the original developer
  are Copyright (C) 2004 Milan Babuskov.

  All Rights Reserved.

  $Id$

  Contributor(s): Nando Dessena, Michael Hieke
*/

//-----------------------------------------------------------------------------
#ifndef FR_COLUMN_H
#define FR_COLUMN_H

#include "metadata/metadataitem.h"

class Domain;
class Table;
//-----------------------------------------------------------------------------
class Column: public MetadataItem
{
private:
    bool notnullM, computedM;
    wxString sourceM, computedSourceM, collationM, defaultM;
protected:
    virtual void loadDescription();
    virtual void saveDescription(wxString description);
public:
    Column();
    void Init(bool notnull, wxString source, wxString computedSource,
        wxString collation, wxString defaultValue);
    virtual wxString getPrintableName();
    wxString getDatatype();
    virtual wxString getDropSqlStatement() const;

    bool isNullable(bool checkDomain = true) const;
    bool isPrimaryKey() const;
    wxString getComputedSource() const;
    wxString getSource() const;
    wxString getCollation() const;
    wxString getDefault() const;
    Domain* getDomain() const;
    Table* getTable() const;
    virtual void acceptVisitor(MetadataItemVisitor* visitor);
};
//-----------------------------------------------------------------------------
#endif
