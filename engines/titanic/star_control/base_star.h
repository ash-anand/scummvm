/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef TITANIC_STAR_CONTROL_SUB3_H
#define TITANIC_STAR_CONTROL_SUB3_H

#include "titanic/support/simple_file.h"
#include "titanic/star_control/star_control_sub4.h"
#include "titanic/star_control/star_control_sub5.h"
#include "titanic/star_control/surface_area.h"

namespace Titanic {

enum StarMode { MODE_STARFIELD = 0, MODE_PHOTO = 1 };

class CStarControlSub12;

struct CBaseStarEntry {
	byte _field0;
	byte _field1;
	byte _field2;
	byte _field3;
	double _value;
	CBaseStarVal _val;
	uint _data[5];

	CBaseStarEntry();
	void load(Common::SeekableReadStream &s);
};

class CBaseStar {
private:
	void draw1(CSurfaceArea *surfaceArea, CStarControlSub12 *sub12, CStarControlSub5 *sub5);
	void draw2(CSurfaceArea *surfaceArea, CStarControlSub12 *sub12, CStarControlSub5 *sub5);
	void draw3(CSurfaceArea *surfaceArea, CStarControlSub12 *sub12, CStarControlSub5 *sub5);
	void draw4(CSurfaceArea *surfaceArea, CStarControlSub12 *sub12, CStarControlSub5 *sub5);
protected:
	Common::Array<CBaseStarEntry> _data;
	CStarControlSub4 _sub4;
	double _minVal;
	double _maxVal;
	double _range;
	double _value1, _value2;
	double _value3, _value4;
protected:
	/**
	 * Get a pointer to a data entry
	 */
	CBaseStarEntry *getDataPtr(int index);

	/**
	 * Load entry data from a passed stream
	 */
	void loadData(Common::SeekableReadStream &s);

	/**
	 * Load entry data from a specified resource
	 */
	void loadData(const CString &resName);

	/**
	 * Reset the data for an entry
	 */
	void resetEntry(CBaseStarEntry &entry);

	void baseFn1(int v1, int v2, int v3, int v4);
	void baseFn2(int v1, int v2);
public:
	CBaseStar();
	virtual ~CBaseStar() {}

	/**
	 * Draw the item
	 */
	virtual void draw(CSurfaceArea *surfaceArea, CStarControlSub12 *sub12, CStarControlSub5 *sub5);

	virtual bool loadYale(int v1) { return true; }

	/**
	 * Selects a star
	 */
	virtual bool selectStar(CSurfaceArea *surfaceArea, CStarControlSub12 *sub12,
		int flags, const Common::Point &pt) { return false; }

	virtual bool proc5(int v1) { return false; }
	virtual bool loadStar() { return false; }

	/**
	 * Load the item's data
	 */
	virtual void load(SimpleFile *file) {}

	/**
	 * Save the item's data
	 */
	virtual void save(SimpleFile *file, int indent) {}

	/**
	 * Clear allocated data
	 */
	void clear();

	void initialize();

	int size() const { return _data.size(); }
};

} // End of namespace Titanic

#endif /* TITANIC_STAR_CONTROL_SUB3_H */
