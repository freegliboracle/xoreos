/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  Progress bar widget for the Odyssey engine.
 */

#ifndef ENGINES_ODYSSEY_PROGRESSBAR_H
#define ENGINES_ODYSSEY_PROGRESSBAR_H

#include <memory>

#include "src/engines/odyssey/widget.h"

namespace Engines {

namespace Odyssey {

class WidgetProgressbar : public Widget {
public:
	WidgetProgressbar(GUI &gui, const Common::UString &tag);

	void load(const Aurora::GFF3Struct &gff);

	// State and constraints

	int getCurrentValue() const;
	int getMaxValue() const;

	void setCurrentValue(int curValue);
	void setMaxValue(int maxValue);

	// Basic visuals

	void show();
	void hide();

	void setProgressFill(const Common::UString &fill);

	// Positioning

	void setPosition(float x, float y, float z);

private:
	std::unique_ptr<Graphics::Aurora::GUIQuad> _progress;

	int _maxValue;
	int _curValue;

	bool _horizontal;

	void update();
};

} // End of namespace Odyssey

} // End of namespace Engines

#endif // ENGINES_ODYSSEY_PROGRESSBAR_H
