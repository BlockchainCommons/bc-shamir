# [Blockchain Commons Shamir Secret Sharing](https://github.com/BlockchainCommons/bc-shamir)

**Implementation of Shamir Secret Sharing for use in [Blockchain Commons](https://www.BlockchainCommons.com) Software Projects**

## Prerequisites

* If [`bc-crypto-base`](https://github.com/blockchaincommons/bc-crypto-base) is not installed, the `configure` step below will fail.

## Installation

```bash
$ ./configure
$ make check
$ sudo make install
```

This sequence runs the module's unit tests.

## Use

1. Link against `libbc_shamir.a` and `libbc_crypto_base.a`.
2. Include the umbrella header in your code:

```c
#include <bc-shamir/bc-shamir.h>
```

## Origin, Authors, Copyright & Licenses

Unless otherwise noted (either in this [/README.md](./README.md) or in the file's header comments) the contents of this repository are Copyright © 2020 by Blockchain Commons, LLC, and are [licensed](./LICENSE) under the [spdx:BSD-2-Clause Plus Patent License](https://spdx.org/licenses/BSD-2-Clause-Patent.html).

The table below establishes provenance (repository of origin, permalink, and commit id) for each source file in this repository. Contributors to these files are listed in the commit history for each file, first in this repo, then in the repo of their origin.

In most cases, the authors, copyright, and license for each file reside in comments in the source. When it does not we have attempted to attribute it accurately below.

| File      | From                                                         | Commit                                                       | Authors & Copyright (c)                                | License                                                     |
| --------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------ | ----------------------------------------------------------- |
| bc-shamir.h | [blockchaincommons/bc-shamir](?) | [?](?) | 2020 Blockchain Commons, LLC  | [BSD-2-Clause-Patent](https://spdx.org/licenses/BSD-2-Clause-Patent.html)                        |

### Used by …

- [bc-slip39](https://github.com/BlockchainCommons/bc-slip39) — Blockchain Common's SLIP39 implementation.

### Derived from…

### Dependencies

- autotools - Gnu Build System from Free Software Foundation ([intro](https://www.gnu.org/software/automake/manual/html_node/Autotools-Introduction.html)).

## Contributing

We encourage public contributions through issues and pull-requests! Please review [CONTRIBUTING.md](./CONTRIBUTING.md) for details on our development process. All contributions to this repository require a GPG signed [Contributor License Agreement](./CLA.md).

### Credits

The following people directly contributed to this repository. You can add your name here by getting involved — the first step is to learn how to contribute from our [CONTRIBUTING.md](./CONTRIBUTING.md) documentation.

| Name              | Role                | Github                                            | Email                                 | GPG Fingerprint                                    |
| ----------------- | ------------------- | ------------------------------------------------- | ------------------------------------- | -------------------------------------------------- |
| Christopher Allen | Principal Architect | [@ChristopherA](https://github.com/@ChristopherA) | \<ChristopherA@LifeWithAlacrity.com\> | FDFE 14A5 4ECB 30FC 5D22  74EF F8D3 6C91 3574 05ED |
| Wolf McNally      | Project Lead        | [@WolfMcNally](https://github.com/wolfmcnally)    | \<Wolf@WolfMcNally.com\>              | 9436 52EE 3844 1760 C3DC  3536 4B6C 2FCF 8947 80AE |

## Responsible Disclosure

We want to keep all our software safe for everyone. If you have discovered a security vulnerability, we appreciate your help in disclosing it to us in a responsible manner. We are unfortunately not able to offer bug bounties at this time.

We do ask that you offer us good faith and use best efforts not to leak information or harm any user, their data, or our developer community. Please give us a reasonable amount of time to fix the issue before you publish it. Do not defraud our users or us in the process of discovery. We promise not to bring legal action against researchers who point out a problem provided they do their best to follow the these guidelines.

### Reporting a Vulnerability

Please report suspected security vulnerabilities in private via email to ChristopherA@LifeWithAlacrity.com (do not use this email for support). Please do NOT create publicly viewable issues for suspected security vulnerabilities.

The following keys may be used to communicate sensitive information to developers:

| Name              | Fingerprint                                        |
| ----------------- | -------------------------------------------------- |
| Christopher Allen | FDFE 14A5 4ECB 30FC 5D22  74EF F8D3 6C91 3574 05ED |

You can import a key by running the following command with that individual’s fingerprint: `gpg --recv-keys "<fingerprint>"` Ensure that you put quotes around fingerprints that contain spaces.
