/*  smplayer, GUI front-end for mplayer.
    Copyright (C) 2006-2015 Ricardo Villalba <rvm@users.sourceforge.net>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "stereo3ddialog.h"

Stereo3dDialog::Stereo3dDialog(QWidget* parent, Qt::WindowFlags f)
	: QDialog(parent, f)
{
	setupUi(this);

	in_combo->addItem(tr("None"), "");
	in_combo->addItem(tr("Side by side parallel"), "sbsl");
	in_combo->addItem(tr("Side by side crosseye"), "sbsr");
	in_combo->addItem(tr("Above-below (left eye above)"), "abl");
	in_combo->addItem(tr("Above-below (right eye above)"), "abr");
	in_combo->addItem(tr("Above-below with half height resolution (left eye above)"), "ab2l");
	in_combo->addItem(tr("Above-below with half height resolution (right eye above)"), "ab2r");

	// Copy the input formats
	for (int n = 0; n < in_combo->count(); n++) {
		out_combo->addItem( in_combo->itemText(n), in_combo->itemData(n) );
	}

	out_combo->addItem(tr("Anaglyph red/cyan gray"), "arcg");
	out_combo->addItem(tr("Anaglyph red/cyan half colored"), "arch");

	out_combo->addItem(tr("Anaglyph red/cyan color"), "arcc");

	adjustSize();
}

Stereo3dDialog::~Stereo3dDialog() {
}

void Stereo3dDialog::setInputFormat(const QString & in) {
	int i = in_combo->findData(in);
	if (i == -1) i = 0;
	in_combo->setCurrentIndex(i);
}

void Stereo3dDialog::setOutputFormat(const QString & out) {
	int i = out_combo->findData(out);
	if (i == -1) i = 0;
	out_combo->setCurrentIndex(i);
}

QString Stereo3dDialog::inputFormat() {
	int i = in_combo->currentIndex();
	return in_combo->itemData(i).toString();
}

QString Stereo3dDialog::outputFormat() {
	int i = out_combo->currentIndex();
	return out_combo->itemData(i).toString();
}

#include "moc_stereo3ddialog.cpp"