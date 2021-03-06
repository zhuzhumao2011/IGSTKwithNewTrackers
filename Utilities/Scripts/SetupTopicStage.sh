#!/usr/bin/env bash
#==========================================================================
#
#   Copyright Insight Software Consortium
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#          http://www.apache.org/licenses/LICENSE-2.0.txt
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#
#==========================================================================*/

die() {
	echo 1>&2 "$@" ; exit 1
}

echo 'Setting up the topic stage...' &&
cd "${BASH_SOURCE%/*}" &&
if ! git config remote.stage.url >/dev/null; then
  git remote add stage git://igstk.org/stage/IGSTK.git &&
  git config remote.stage.pushurl git@igstk.org:stage/IGSTK.git
fi || die 'Could not add the topic stage remote.'
