/*******************************************************************************
 *
 *                             Messenger Backend
 *     Copyright (C) 2016 Björn Petersen Software Design and Development
 *                   Contact: r10s@b44t.com, http://b44t.com
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see http://www.gnu.org/licenses/ .
 *
 *******************************************************************************
 *
 * File:    mrchat.h
 * Authors: Björn Petersen
 * Purpose: MrChat represents a single chat - this is a conversation with
 *          a single user or a group
 *
 ******************************************************************************/


#ifndef __MRCHAT_H__
#define __MRCHAT_H__


class MrMailbox;


class MrChat
{
public:
	// if a chat object is no longer needed, they should be Release()'d, to destroy a chat physically,
	// call Destroy() (an additional Release() is needed even in this case)
	void         Release     () { delete this; }
	void         Destroy     ();

private:
	// as chat objects are only constructed by MrMailbox, we declare the constructor as private and MrMailbox as a friend
	             MrChat      (MrMailbox*);
	             ~MrChat     ();
	friend class MrMailbox;

	// the mailbox, the chat belongs to
	MrMailbox*   m_mailbox;
};


#endif // __MRCHAT_H__

