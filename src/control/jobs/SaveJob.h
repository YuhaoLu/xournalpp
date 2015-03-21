/*
 * Xournal++
 *
 * A job which saves a Document
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __SAVEJOB_H__
#define __SAVEJOB_H__

#include "BlockingJob.h"
#include <StringUtils.h>
#include <XournalType.h>

class SaveJob : public BlockingJob
{
public:
	SaveJob(Control* control);

protected:
	virtual ~SaveJob();

public:
	virtual void run();

	bool save();

private:
	static void copyProgressCallback(goffset current_num_bytes,
	                                 goffset total_num_bytes,
	                                 gpointer user_data);
	bool copyFile(string source, string target);

	void updatePreview();
	virtual void afterRun();

private:
	XOJ_TYPE_ATTRIB;

	string copyError;

	string lastError;

};

#endif /* __SAVEJOB_H__ */
