# bs-react-test-renderer

[![Build Status][travis-image]][travis-url]
[![npm][npm-image]][npm-url]
[![dependencies][deps-image]][deps-url]
[![devDependencies][depsdev-image]][depsdev-url]

> [BuckleScript](//github.com/bloomberg/bucklescript) bindings for [react-test-renderer](//github.com/facebook/react/tree/master/packages/react-test-renderer).

## Installation

```sh
$ yarn add --dev bs-react-test-renderer

# or..

$ npm install --save-dev bs-react-test-renderer
```

## Usage

#### Add to `bsconfig.json`

```json
{
  "bs-dev-dependencies": [
    "bs-react-test-renderer"
  ]
}
```

#### With [`bs-jest`](//github.com/BuckleTypes/bs-jest)

```reason
// Component_test.re

open Jest;
open ExpectJs;

let _ =

describe "Component" (fun _ => {
  test "renders" (fun _ => {
    let component = ReactShallowRenderer.renderWithRenderer <Component />;

    expect (Js.Undefined.return component) |> toBeDefined;
  });
});
```

## Examples

See [`src/__tests__`](//github.com/BuckleTypes/bs-react-test-renderer/tree/master/src/__tests__) for some examples.

For examples with Snapshot testing with [`bs-jest`](//github.com/BuckleTypes/bs-jest), see [`reason-calculator`](//github.com/wyze/reason-calculator).

## Development

```sh
$ git clone https://github.com/BuckleTypes/bs-react-test-renderer.git
$ cd bs-react-test-renderer
$ yarn # or `npm install`
```

## Build

```sh
$ yarn build
```

## Test

```sh
$ yarn test
```

## Change Log

> [Full Change Log](changelog.md)

### [v1.0.0](https://github.com/BuckleTypes/bs-react-test-renderer/releases/tag/v1.0.0) (2017-04-14)

* [[`3b87107de8`](https://github.com/BuckleTypes/bs-react-test-renderer/commit/3b87107de8)] - Initial commit (Neil Kistner)

## License

MIT © [Neil Kistner](https://neilkistner.com)

[travis-image]: https://img.shields.io/travis/BuckleTypes/bs-react-test-renderer.svg?style=flat-square
[travis-url]: https://travis-ci.org/BuckleTypes/bs-react-test-renderer

[npm-image]: https://img.shields.io/npm/v/bs-react-test-renderer.svg?style=flat-square
[npm-url]: https://npm.im/bs-react-test-renderer

[deps-image]: https://img.shields.io/david/BuckleTypes/bs-react-test-renderer.svg?style=flat-square
[deps-url]: https://david-dm.org/BuckleTypes/bs-react-test-renderer

[depsdev-image]: https://img.shields.io/david/dev/BuckleTypes/bs-react-test-renderer.svg?style=flat-square
[depsdev-url]: https://david-dm.org/BuckleTypes/bs-react-test-renderer?type=dev
