//  Created by Theo Penavaire on 05/31/2018
//  Last Update on 06/07/2018 

#include "AFSManager.h"

namespace tp_filesystem
{
	bool	AFSManager::FSIsExtension(const std::string& path,
									  const std::string& ext) const
	{
		return path.substr(path.find_last_of('.') + 1) == ext;
	}

	bool	AFSManager::FSFolderExists(const std::string &path) const
	{
		struct stat info;

		return stat(path.c_str(), &info) != 0 && (info.st_mode & S_IFDIR);
	}

	std::string	AFSManager::FSGetFileExtension(const std::string &path) const {
		return path.substr(path.find_last_of('.') + 1);
	}

}
