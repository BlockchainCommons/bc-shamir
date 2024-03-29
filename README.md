# [Blockchain Commons Shamir Secret Sharing](https://github.com/BlockchainCommons/bc-shamir)

### _by [Wolf McNally](https://www.github.com/wolfmcnally) and [Christopher Allen](https://www.github.com/ChristopherA)_ with [Chris Howe](https://www.github.com/howech)

* <img src="https://github.com/BlockchainCommons/crypto-commons/blob/master/images/logos/crypto-commons-super-simple.png" width=16 valign="bottom">&nbsp;&nbsp; ***part of the [crypto commons](https://github.com/BlockchainCommons/crypto-commons/blob/master/README.md) technology family***

**Blockchain Commons Shamir Secret Sharing** is an implementation of Shamir Secret Sharing for use in [Blockchain Commons](https://www.BlockchainCommons.com) Software Projects.

## Prerequisites

* If [`bc-crypto-base`](https://github.com/blockchaincommons/bc-crypto-base) is not installed, the `configure` step below will fail.

## Installation Instructions

This sequence also runs the module's unit tests.

```bash
$ ./configure
$ make check
$ sudo make install
```

## Usage Instructions

1. Link against `libbc-shamir.a` and `libbc-crypto-base.a`.
2. Include the umbrella header in your code:

```c
#include <bc-shamir/bc-shamir.h>
```

## Notes for Maintainers

Before accepting a PR that can affect build or unit tests, make sure the following sequence of commands succeeds:

```bash
$ ./configure
$ make lint
$ make distcheck
$ make distclean
```

`make lint` uses [Cppcheck](https://en.wikipedia.org/wiki/Cppcheck) to perform static analysis on the code. All PRs should pass with no warnings.

`make distcheck` builds a distribution tarball, unpacks it, then configures, builds, and runs unit tests from it, then performs an install and uninstall from a non-system directory and makes sure the uninstall leaves it clean. `make distclean` removes all known byproduct files, and unless you've added files of your own, should leave the directory in a state that could be tarballed for distribution. After a `make distclean` you'll have to run `./configure` again.

## Status - Released & Reviewed

This released project has received a [security review](SECURITY-REVIEW.md).

## Origin, Authors, Copyright & Licenses

Unless otherwise noted (either in this [/README.md](./README.md) or in the file's header comments) the contents of this repository are Copyright © 2020 by Blockchain Commons, LLC, and are [licensed](./LICENSE) under the [spdx:BSD-2-Clause Plus Patent License](https://spdx.org/licenses/BSD-2-Clause-Patent.html).

In most cases, the authors, copyright, and license for each file reside in header comments in the source code. When it does not we have attempted to attribute it accurately in the table below.

This table below also establishes provenance (repository of origin, permalink, and commit id) for files included from repositories that are outside of this repository. Contributors to these files are listed in the commit history for each repository, first with changes found in the commit history of this repo, then in changes in the commit history of their repo of their origin.

| File      | From                                                         | Commit                                                       | Authors & Copyright (c)                                | License                                                     | Notes                                                     |
| --------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------ | ----------------------------------------------------------- | ---------------------- |
| hazmat.c | [dsprenkels/sss](https://github.com/dsprenkels/sss/blob/487021e257542fdb292300dfb411654103027b6c/hazmat.c) | [b613717](https://github.com/dsprenkels/sss/commit/b613717c2b849b497da7e77c313897fa2d59bb6f) | Copyright 2017 Daan Sprenkels <hello@dsprenkels.com>  | [MIT](https://spdx.org/licenses/MIT.html)                        | We have commented out sss_create_keyshares & sss_combine_keyshares. |
| hazmat.h | [dsprenkels/sss](https://github.com/dsprenkels/sss/blob/487021e257542fdb292300dfb411654103027b6c/hazmat.c) | [b613717](https://github.com/dsprenkels/sss/commit/b613717c2b849b497da7e77c313897fa2d59bb6f) | Copyright 2017 Daan Sprenkels <hello@dsprenkels.com>  | [MIT](https://spdx.org/licenses/MIT.html)                        |
| shamir.c | [dsprenkels/sss](https://github.com/dsprenkels/sss/) | | Copyright 2017 Daan Sprenkels <hello@dsprenkels.com>  | [MIT](https://spdx.org/licenses/MIT.html)                        | We have commented out sss_create_keyshares & sss_combine_keyshares. |
| shamir.h | [dsprenkels/sss](https://github.com/dsprenkels/sss/) | | Copyright 2017 Daan Sprenkels <hello@dsprenkels.com>  | [MIT](https://spdx.org/licenses/MIT.html)                        |

### Used with…

These are other projects that work with or leverage `bc-shamir`:

- [bc-slip39](https://github.com/BlockchainCommons/bc-slip39) — Blockchain Common's SLIP-39 implementation.
- [lethekit](https://github.com/BlockchainCommons/bc-lethekit) — Open source DIY hardware box for offline cryptographic tools by Blockchain Commons

### Derived from…

The Blockchain Commons Shamir project is either derived from or was inspired by:

- Portions of this source code comes from [dsprenkels/sss](https://github.com/dsprenkels/sss/) by Daan Sprenkels [@dspenkels](https://github.com/dsprenkels) <hello@dsprenkels.com> licensed [MIT](https://spdx.org/licenses/MIT.html).

### Dependencies

- autotools - Gnu Build System from Free Software Foundation ([intro](https://www.gnu.org/software/automake/manual/html_node/Autotools-Introduction.html)).

## Financial Support

*Blockchain Commons Shamir Secret Sharing* is a project of [Blockchain Commons](https://www.blockchaincommons.com/). We are proudly a "not-for-profit" social benefit corporation committed to open source & open development. Our work is funded entirely by donations and collaborative partnerships with people like you. Every contribution will be spent on building open tools, technologies, and techniques that sustain and advance blockchain and internet security infrastructure and promote an open web.

To financially support further development of *Blockchain Commons Shamir Secret Sharing* and other projects, please consider becoming a Patron of Blockchain Commons through ongoing monthly patronage as a [GitHub Sponsor](https://github.com/sponsors/BlockchainCommons). You can also support Blockchain Commons with bitcoins at our [BTCPay Server](https://btcpay.blockchaincommons.com/).

## Contributing

We encourage public contributions through issues and pull-requests! Please review [CONTRIBUTING.md](./CONTRIBUTING.md) for details on our development process. All contributions to this repository require a GPG signed [Contributor License Agreement](./CLA.md).

### Discussions

The best place to talk about Blockchain Commons and its projects is in our GitHub Discussions areas.

[**Gordian Developer Community**](https://github.com/BlockchainCommons/Gordian-Developer-Community/discussions). For standards and open-source developers who want to talk about interoperable wallet specifications, please use the Discussions area of the [Gordian Developer Community repo](https://github.com/BlockchainCommons/Gordian-Developer-Community/discussions). This is where you talk about Gordian specifications such as [Gordian Envelope](https://github.com/BlockchainCommons/Gordian/tree/master/Envelope#articles), [bc-shamir](https://github.com/BlockchainCommons/bc-shamir), [Sharded Secret Key Reconstruction](https://github.com/BlockchainCommons/bc-sskr), and [bc-ur](https://github.com/BlockchainCommons/bc-ur) as well as the larger [Gordian Architecture](https://github.com/BlockchainCommons/Gordian/blob/master/Docs/Overview-Architecture.md), its [Principles](https://github.com/BlockchainCommons/Gordian#gordian-principles) of independence, privacy, resilience, and openness, and its macro-architectural ideas such as functional partition (including airgapping, the original name of this community).

[**Blockchain Commons Discussions**](https://github.com/BlockchainCommons/Community/discussions). For developers, interns, and patrons of Blockchain Commons, please use the discussions area of the [Community repo](https://github.com/BlockchainCommons/Community) to talk about general Blockchain Commons issues, the intern program, or topics other than those covered by the [Gordian Developer Community](https://github.com/BlockchainCommons/Gordian-Developer-Community/discussions) or the 
[Gordian User Community](https://github.com/BlockchainCommons/Gordian/discussions).
### Other Questions & Problems

As an open-source, open-development community, Blockchain Commons does not have the resources to provide direct support of our projects. Please consider the discussions area as a locale where you might get answers to questions. Alternatively, please use this repository's [issues](./issues) feature. Unfortunately, we can not make any promises on response time.

If your company requires support to use our projects, please feel free to contact us directly about options. We may be able to offer you a contract for support from one of our contributors, or we might be able to point you to another entity who can offer the contractual support that you need.


### Credits

The following people directly contributed to this repository. You can add your name here by getting involved — the first step is to learn how to contribute from our [CONTRIBUTING.md](./CONTRIBUTING.md) documentation.

| Name              | Role                | Github                                            | Email                                 | GPG Fingerprint                                    |
| ----------------- | ------------------- | ------------------------------------------------- | ------------------------------------- | -------------------------------------------------- |
| Christopher Allen | Principal Architect | [@ChristopherA](https://github.com/ChristopherA) | \<ChristopherA@LifeWithAlacrity.com\> | FDFE 14A5 4ECB 30FC 5D22  74EF F8D3 6C91 3574 05ED |
| Wolf McNally      | Project Lead        | [@WolfMcNally](https://github.com/wolfmcnally)    | \<Wolf@WolfMcNally.com\>              | 9436 52EE 3844 1760 C3DC  3536 4B6C 2FCF 8947 80AE |
| Chris Howe        | Occasional Contributor| [@howech](https://github.com/howech)            | \<chris@howeville.com\>               | 7C3D D38E 16D0 0275 5C0B  82B4 709C 6DA6 EAD3 99A7 |

# Responsible Disclosure

We want to keep all our software safe for everyone. If you have discovered a security vulnerability, we appreciate your help in disclosing it to us in a responsible manner. We are unfortunately not able to offer bug bounties at this time.

We do ask that you offer us good faith and use best efforts not to leak information or harm any user, their data, or our developer community. Please give us a reasonable amount of time to fix the issue before you publish it. Do not defraud our users or us in the process of discovery. We promise not to bring legal action against researchers who point out a problem provided they do their best to follow the these guidelines.

### Reporting a Vulnerability

Please report suspected security vulnerabilities in private via email to ChristopherA@BlockchainCommons.com (do not use this email for support). Please do NOT create publicly viewable issues for suspected security vulnerabilities.

The following keys may be used to communicate sensitive information to developers:

| Name              | Fingerprint                                        |
| ----------------- | -------------------------------------------------- |
| Christopher Allen | FDFE 14A5 4ECB 30FC 5D22  74EF F8D3 6C91 3574 05ED |

You can import a key by running the following command with that individual’s fingerprint: `gpg --recv-keys "<fingerprint>"` Ensure that you put quotes around fingerprints that contain spaces.
