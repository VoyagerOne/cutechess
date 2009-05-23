/*
    This file is part of Cute Chess.

    Cute Chess is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Cute Chess is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Cute Chess.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "enginefactory.h"
#include "xboardengine.h"
#include "uciengine.h"

ChessEngine* EngineFactory::createEngine(ChessEngine::Protocol protocol,
                                         QIODevice* ioDevice, QObject* parent)
{
	Q_ASSERT(ioDevice != 0);

	switch (protocol)
	{
		case ChessEngine::Xboard:
			return new XboardEngine(ioDevice, parent);
		break;

		case ChessEngine::Uci:
			return new UciEngine(ioDevice, parent);
		break;

		default:
			return 0;
		break;
	}
}
