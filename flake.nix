{
  description = "Math 215 HPC Shenanigans";

  inputs.flake-utils.url = "github:numtide/flake-utils";
  inputs.nixpkgs.url = "nixpkgs";

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem
      (system:
        let pkgs = import nixpkgs { inherit system; }; in
        {
          devShells.default = pkgs.mkShell {
					  name="math215";
						packages=with pkgs;[gcc gnumake clang-tools llvmPackages.openmp ];
        	};
				});
} 
